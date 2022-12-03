import usb.core
import usb.backend.libusb1
import json
import time
from enum import Enum

# Status codes
class CiaaStatusCode(Enum):
    CIAA_NOT_FOUND = -1
    CIAA_FOUND = 0


class Ciaa():

    __VENDOR_ID = 0x1fc9
    __PRODUCT_ID = 0x008a
    __WRITE_ED = 0x01
    __READ_ED = 0x81

    def __init__(self, **kwargs):
        """
        Initiates a CIAA USB handler

        params:
            product_id (int): Product ID of the CIAA (hexadecimal)
        """
        if "product_id" in kwargs:
            self.__PRODUCT_ID = kwargs["product_id"]


    def find(self) -> CiaaStatusCode:
        """
        Try to find a CIAA connected to USB

        returns: (CIAAStatusCode) Status code
        """
        # Find device by vendor and product IDs
        self.__dev = usb.core.find(idVendor=self.__VENDOR_ID, idProduct=self.__PRODUCT_ID)

        # Check if it was found
        if self.__dev is None:
            # If not, return error message
            return CiaaStatusCode.CIAA_NOT_FOUND

        return CiaaStatusCode.CIAA_FOUND


    def write(self, msg: str) -> int:
        """
        Sends a string through USB

        params:
            msg (str): string to send

        return: (int) How many bytes were sent
        """
        # Number of bytes written
        bytes_written = 0

        try:
            # Try to send bytes
            bytes_written = self.__dev.write(self.__WRITE_ED, msg.encode("utf-8"))
        except usb.core.USBError as e:
            # Catch and print exception
            print(f"Error when writing: {e.args}")
        # Return number of bytes sent
        return bytes_written

    
    def read(self, timeout: int = 100) -> str:
        """
        Reads a string from USB

        params:
            timeout (int): time to wait in ms

        return: (str) String read
        """
        try:
            # Try to read bytes (returns list)
            data = self.__dev.read(self.__READ_ED, 128, timeout)
        except usb.core.USBError as e:
            # Catch exception and return None
            return None

        # Join list to a string
        byte_str = ''.join(chr(n) for n in data) 
        # Remove null characters
        result = byte_str.split('\x00', 1)[0]
        # If nothing was read
        if len(result) == 0:
            # Return empty
            return None
        # Return full string
        return result


    def read_json(self, timeout: int = 100, debug: bool = False) -> str:
        """
        Reads a JSON from USB

        params:
            timeout (int): time to wait in ms
            debug (bool): True to print timestamps in console

        return: (dict) Dictionary object
        """
        bytes_read = ""
        data = ""
        # Only when debug flag is true
        if debug:
            # Starting time timestamp
            start_time = time.time()

        # Look for closing JSON character
        while not "}" in bytes_read:
            # Read from USB
            bytes_read = self.read(timeout)
            # Check if any byte was read
            if bytes_read != None:
                # Add bytes to data
                data += bytes_read
            else:
                # Clear bytes
                bytes_read = ""

        # Only when debug flag is true
        if debug:
            # Show how much time it has passed since the beginnig of the transfer
            print(f"Data transfer done in: {(time.time() - start_time):.2e}s")
        
        # Build JSON like object with byte array data
        data = json.loads(data)
        return data

    def get_resolution_bits(self, nclocks: int) -> int:
        """
        Get the number of bits of ADC resolution from the clocks
        needed to finish the conversion

        params:
            nclocks (int): number of clocks

        return (int): resolution bits (3 to 10)
        """
        return nclocks - 1