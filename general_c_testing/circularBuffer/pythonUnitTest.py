#!/usr/bin/python

import ctypes, os

#class gen_test_values():

class struct_def(ctypes.Structure):
    _fields_=[
            ("vm", ctypes.c_int16 * 16),
            ("hd", ctypes.c_int32),
            ("full", ctypes.c_bool)]

class load_lib():
    def __init__(self):
        self.dll = ctypes.cdll.LoadLibrary(os.path.join(os.path.dirname(__file__), "libcircularBuffer.so"))
        self.dll = ctypes.CDLL(os.path.join(os.path.dirname(__file__), "libcircularBuffer.so"))
    def clear_array(self):
        self.dll.hm_srt_battery_buffer_clear()

    def put_value(self, voltage_mv: int) -> int:
        retval = ctypes.c_uint32()
        retval = self.dll.hm_srt_battery_buffer_put_item(voltage_mv)
        return retval

    def get_size(self):
        retval = ctypes.c_uint32()
        retval = self.dll.hm_srt_battery_buffer_get_size()
        return retval

    def get_head(self) -> int:
        pointer=ctypes.POINTER(struct_def)

        ptr = self.dll.getArrayPtr
        ptr.restype = pointer
        m = pointer()
        m = ptr()
        print(m.contents.hd)

    def print_array(self):
        self.dll.printArray()

if __name__ == "__main__":
    lib = load_lib()
    lib.clear_array()
    lib.print_array()
    lib.put_value(3400)
    lib.print_array()
    lib.get_head()
