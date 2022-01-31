# Azure Sphere RemoteX Client Library

The RemoteX project provides remote access to Azure Sphere peripherals from a POSIX C application. The project is similar in nature to the [Raspberry Pi Remote GPIO](https://gpiozero.readthedocs.io/en/stable/remote_gpio.html) with the [pigpio C Interface](http://abyz.me.uk/rpi/pigpio/cif.html) and [Arduino Firmata](https://docs.arduino.cc/hacking/software/FirmataLibrary) projects. 

Refer to the [DesktopDevX and RemoteX wiki](https://github.com/Azure-Sphere-DevX/DesktopDevX.Examples/wiki) video for information on the [AzureSphereRemoteX Server](https://github.com/Azure-Sphere-DevX/AzureSphereRemoteX.Server) and [Azure Sphere Client Library](https://github.com/Azure-Sphere-DevX/AzureSphereRemoteX.Client).

## Architecture

[![ Azure Sphere RemoteX](https://github.com/Azure-Sphere-DevX/DesktopDevX.Examples/wiki/media/AzureSphereRemoteX.png)](https://youtu.be/jWPutk1xNt8)

## Including the Azure Sphere RemoteX client library in your project

You would normally submodule the RemoteX client library into your project

```bash
git submodule add https://github.com/Azure-Sphere-DevX/AzureSphereRemoteX.Client.git AzureSphereRemoteX
```

## CMakeLists.txt updates

Update the project CMakeLists.txt file to make the AzureSphereRemoteX client library available in yout project.

```cmake
################################################################################
# Following lines required for AzureSphereRemoteX
add_subdirectory("AzureSphereRemoteX" applibs)
target_link_libraries(${PROJECT_NAME} "applibs")
################################################################################
```
