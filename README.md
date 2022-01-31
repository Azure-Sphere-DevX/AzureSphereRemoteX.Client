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

## Examples using the RemoteX Client Library

You can find examples for the RemoteX Client libary at the following locations:

- [DesktopDevX Examples](https://github.com/Azure-Sphere-DevX/DesktopDevX.Examples)
- [AzureSphereDevX.Examples](https://github.com/Azure-Sphere-DevX/AzureSphereDevX.Examples)

## CMakeLists.txt updates

### Add reference to the RemoteX client library

Update the project CMakeLists.txt file to make the AzureSphereRemoteX client library available in yout project.

```cmake
################################################################################
# Following lines required for AzureSphereRemoteX
add_subdirectory("AzureSphereRemoteX" applibs)
target_link_libraries(${PROJECT_NAME} "applibs")
################################################################################
```

### Azure Sphere RemoteX Server IP Address

This is the address of the Azure Sphere running the [AzureSphereRemoteX.Server](https://github.com/Azure-Sphere-DevX/AzureSphereRemoteX.Server) to your CMakeLists.txt file.

```cmake
add_compile_definitions(AZURE_SPHERE_REMOTEX_IP="192.168.10.117")
```

#### SPI peripheral performance mode

Enabling this flag in the CMakeLists.txt file will improve performance of SPI peripherals that don't require a response. For example a LED 8x8 Panel.

```cmake
add_compile_definitions(AZURE_SPHERE_REMOTEX_PERFORMANCE_MODE)
```
