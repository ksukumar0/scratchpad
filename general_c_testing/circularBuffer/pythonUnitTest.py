import ctypes

if __name__ == "__main__":
    dll = ctypes.cdll.LoadLibrary(os.path.join(os.path.dirname(__file__), "libcircularBuffer.so"))
