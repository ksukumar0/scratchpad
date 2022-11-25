#!/usr/bin/python
import os

def test_file_exists(filename):
    #try:
    #    with open(filename, 'xb') as f:
    #        print("Success: {} opened".format(filename))

    #except IOError:
    #    print("Error: {} exists".format(filename))
    overwrite =False
    file_data = b'Hi there'
    try:
        if overwrite == True:
            f=open(filename, 'wb')
            f.write(file_data)
        else:
            f=open(filename, 'xb')
            f.write(file_data)
    except IOError:
            print("Cant write to {} as file already exists".format(filename))
    except Exception as e:
            print(e)

if __name__ == "__main__":
    file_name_exists = "test_exists"
    try:
        os.remove(file_name_exists)
    except Exception as e:
        pass
    test_file_exists(file_name_exists)
    test_file_exists(file_name_exists)

