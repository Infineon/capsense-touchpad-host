# CAPSENSE™ Touchpad I2C Host Release Notes

Refer to the [README](./README.md) and [CAPSENSE™ Touchpad I2C Host API Reference Manual](https://infineon.github.io/capsense-touchpad-host/html/index.html) for a complete description of the middleware.

## What's Included?

To view the full list of changes, refer to [Changelog section](https://infineon.github.io/capsense-touchpad-host/html/index.html#section_changelog).

## Known Issues and Limitations

* The middleware supports one touchpad interface per context.
* The platform-neutral port template requires a host-specific implementation.
* Hardware applications require the touchpad secondary firmware and a
  correctly configured 1000 kHz I2C interface.

## Supported Software and Tools

The reference port and repository tests were validated with the following
software and tools:

| Software and Tools                                      | Version |
| :---                                                    | :----:  |
| GCC Compiler                                            | 14.2.1  |
| IAR Compiler                                            | 9.70.1  |
| ARM Compiler 6                                          | 6.22    |
| LLVM ARM Compiler                                       | 19.1.5  |

## More Information

For more information, refer to the following documents:

* [CAPSENSE™ Touchpad I2C Host README](./README.md)
* [Porting Guide](./port/PORTING_GUIDE.md)
* [ModusToolbox™ Software Environment](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
* [Infineon Technologies AG](https://www.infineon.com)

---
Copyright (c) 2025-2026, Infineon Technologies AG or an affiliate of Infineon Technologies AG.
