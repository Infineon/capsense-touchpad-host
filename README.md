# CAPSENSE™ Touchpad I2C Host

## Overview

CAPSENSE™ Touchpad I2C Host is portable middleware for controlling an Infineon
PSOC™ 4000T CAPSENSE™ touchpad from a bare-metal or RTOS-based host MCU. It
provides C APIs for touch coordinates, gestures, configuration, diagnostics,
sensor data and user data.

The portable core uses application-provided I2C callbacks and does not depend
on a specific MCU, RTOS, ModusToolbox™, or Peripheral Driver Library (PDL). A
PSOC™ Edge reference port and a platform-neutral port template are included.

### Features

* Portable middleware core
* Callback-based I2C interface
* Touch position and gesture APIs
* Configuration, diagnostics, and sensor-data APIs
* User-data operations
* PSOC™ Edge reference port for `KIT_PSE84_EVAL_EPC2`
* Port template for other host platforms

## Quick Start

Refer to the [CAPSENSE™ Touchpad I2C Host API Reference](https://infineon.github.io/capsense-touchpad-host/html/index.html) for a complete Quick Start Guide.

Add the middleware public header and source to the application, implement the
I2C read and write callbacks, and initialize a context:

```c
#include "mtb_touchpad_driver.h"

static mtb_touchpad_intf_context_t touchpad_context;

MTB_TOUCHPAD_RET_TYPE result = mtb_touchpad_init(
    application_touchpad_write,
    application_touchpad_read,
    NULL,
    &touchpad_context);
```

The touchpad and host I2C controller must be initialized before calling
`mtb_touchpad_init()`. Always check the returned status before using API output
values.

For port requirements and transaction diagrams, refer to the [porting guide](./port/PORTING_GUIDE.md).

## Supported Toolchains

Refer to [Release Notes](./RELEASE.md) for a list of supported toolchains.

## Related Projects

* [Linux I2C Touchpad Driver](https://github.com/Infineon/linux-i2c-touchpad)
* [PSOC™ 4 MSC-LP Smart Glass Touchpad](https://github.com/Infineon/mtb-example-psoc4-msclp-smart-glass-touchpad)

## More Information

For more information, refer to the following documents:

* [CAPSENSE™ Touchpad I2C Host API Reference Manual](https://infineon.github.io/capsense-touchpad-host/html/index.html)
* [Porting Guide](./port/PORTING_GUIDE.md)
* [Release Notes](./RELEASE.md)
* [ModusToolbox™ Software Environment](https://www.infineon.com/cms/en/design-support/tools/sdk/modustoolbox-software/)
* [Infineon Technologies AG](https://www.infineon.com)


---
Copyright (c) 2025-2026, Infineon Technologies AG or an affiliate of Infineon Technologies AG.
