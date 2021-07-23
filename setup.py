from distutils.core import setup, Extension

def main():

    setup(name="_inotify",
        version="1.0.0",
        description="Python interface for the fputs C library function",
        author="kuttler",
        author_email="kuttler40@gmail.com",
        ext_modules=[Extension("_inotify", ["_inotify.c"])])
 
if __name__ == "__main__":
     main()

 

