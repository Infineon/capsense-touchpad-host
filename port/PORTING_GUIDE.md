# CAPSENSE™ Touchpad I2C Host porting guide

## Overview

The CAPSENSE™ Touchpad I2C Host middleware is platform independent.
Platform-specific functionality is implemented in the `port/` directory.

The repository currently provides the following ports:

```
port/
├── psoc_edge/
│   ├── mtb_touchpad_i2c_port.c
│   └── mtb_touchpad_i2c_port.h
└── template/
    ├── mtb_touchpad_i2c_port_template.c
    └── mtb_touchpad_i2c_port_template.h
```

Developers targeting other platforms should use the PSOC Edge implementation
as a reference, and the `template/` files as a starting point.

---

## Port Layer Responsibilities

A platform port must provide implementations of the following functions:

```c
uint32_t touchpad_i2c_init(void);

uint32_t touchpad_i2c_read(uint16_t subaddress,
                           uint8_t *data,
                           uint16_t length,
                           void *intf_ptr);

uint32_t touchpad_i2c_write(uint16_t subaddress,
                            uint8_t *data,
                            uint16_t length,
                            void *intf_ptr);
```

These functions are responsible for:

- Initializing the platform I2C peripheral
- Reading data from the touchpad over I2C
- Writing data to the touchpad over I2C

---

## Reference Implementation

The PSOC Edge implementation uses the PDL SCB I2C driver:

- `Cy_SCB_I2C_Init()`
- `Cy_SCB_I2C_MasterRead()`
- `Cy_SCB_I2C_MasterWrite()`
- `Cy_SCB_I2C_Enable()`

Equivalent APIs from another platform may be used instead.

---

## Required I2C Transactions

### Register Read

```
START
Slave Address + Write
Register Address MSB
Register Address LSB
REPEATED START
Slave Address + Read
Read N bytes
STOP
```

### Register Write

```
START
Slave Address + Write
Register Address MSB
Register Address LSB
Write N bytes
STOP
```

---

## Platform Configuration

Platform-specific configuration should remain in the port layer, including:

- I2C peripheral instance
- SDA/SCL pin assignment
- Interrupt configuration
- Interrupt priority
- I2C clock frequency must be 1000 KHz
- Device address is fixed and it is 0x0D

---

## Creating a New Port

1. Copy the files from the template/ directory and rename them to match the target platform.
2. Implement the platform-specific I2C APIs in the marked TODO sections, using the PSOC Edge port as a reference.
3. Keep the same public function prototypes.
4. No changes should be required in the portable middleware core.
