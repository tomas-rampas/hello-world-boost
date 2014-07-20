This is a result of my effort of creation experimental HelloWorld library incorporating Boost 1.5.5 (compiled and lib and includes directories being referenced from Visual Studio). So here is my really stupid simple sample of HelloWorld that is based on slightly changed code available in Boost documentation.
The main intention of my HelloWorld sample was to create simple C++ wrapper that would be callable from my local Python environment. So for having library to be callable from Python there are some steps that are really important and are not aforementioned in Boost documentation (maybe I've overlooked them):

-> Resulting DLL has to be renamed to PYD. Python interpreted does not load DLL (At least I was not successful in convincing an interpreter to do that)

-> Resulting PYD library has to have the same name like parameter of BOOST_PYTHON_ MODULE(...). So in my case I have hello as a parameter so correspondingly my compiled module is named hello.pyd.

-> PYD file has to be available/findable for Python interpreter. Verify that your file is in corresponding %PYTHONPATH%. Otherwise Python's import hello (in my case) would cause runtime errors.
