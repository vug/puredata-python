# A "Hello World" example for Pure Data externals

C code taken from https://github.com/pure-data/externals-howto

## Compilation and building

- Unfortunately Pure Data is only distributed in 32-bit version on Windows. See
  - https://puredata.info/downloads
  - https://github.com/agraef/purr-data/releases
  - https://puredata.info/docs/developer/Windows64BitMinGWX64
  - https://puredata.info/docs/64BitSupport/ "We are getting very close to complete 64-bit compatibility"
- Get a 32-bit MingGW
- `cd pd-helloworld`
- Use make commands
  - `mingw32-make.exe` to produce helloworld.dll for Vanilla Pure Data
  - `mingw32-make.exe TARGET=purr` to produce helloworld.dll for Purr Data
  - `mingw32-make.exe clean` to delete `helloworld.o` and `helloworld.dll`
