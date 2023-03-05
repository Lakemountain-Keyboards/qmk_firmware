
#define SPLIT_MAX_CONNECTION_ERRORS 10

//#define SPLIT_WPM_ENABLE
//#define SPLIT_OLED_ENABLE
//#define SPLIT_POINTIN_ENABLE

#define MATRIX_ROWS 10
#define MATRIX_COLS 9

#define MATRIX_ROW_PINS \
    { A7, A8, B15, B14, B13 }
#define MATRIX_COL_PINS \
    { A15, A14, A13, B7, B10, B2, B6 }
#define MATRIX_ROW_PINS_RIGHT \
    { A7, A8, B15, B14, B13 }
#define MATRIX_COL_PINS_RIGHT \
    { A15, A14, A13, B7, B10, B2, B6 }

#define USB_VBUS_PIN A9
#define SPLIT_HAND_PIN C14

#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 3000

#define DYNAMIC_KEYMAP_LAYER_COUNT 16
#define LAYER_STATE_16BIT

/* serial.c configuration for split keyboard */
#define SERIAL_USART_FULL_DUPLEX // Enable full duplex operation mode.
#define SERIAL_USART_TX_PIN A2
#define SERIAL_USART_RX_PIN A3
#define SERIAL_USART_DRIVER SD2
#define SERIAL_USART_TX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_RX_PAL_MODE 7 // Pin "alternate function", see the respective datasheet for the appropriate values for your MCU. default: 7
#define SERIAL_USART_TIMEOUT 100   // USART driver timeout. default 100
#define SERIAL_USART_SPEED 921600

#define CRC8_USE_TABLE
#define CRC8_OPTIMIZE_SPEED

/* i2c config for oleds */
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN B8
#define I2C1_SDA_PIN B9
#define I2C1_SCL_PAL_MODE 4
#define I2C1_SDA_PAL_MODE 4
#define I2C1_CLOCK_SPEED 400000
#define I2C1_DUTY_CYCLE FAST_DUTY_CYCLE_16_9

/* spi config for eeprom and pmw3360 sensor */
#define SPI_DRIVER                           SPID1
#define SPI_SCK_PIN                          B3
#define SPI_SCK_PAL_MODE                     5
#define SPI_MOSI_PIN                         B5
#define SPI_MOSI_PAL_MODE                    5
#define SPI_MISO_PIN                         B4
#define SPI_MISO_PAL_MODE                    5

/* eeprom config */
#define EXTERNAL_EEPROM_SPI_SLAVE_SELECT_PIN A1
#define EXTERNAL_EEPROM_SPI_CLOCK_DIVISOR 64

/* pmw3360 config  */
#define PMW33XX_CS_PIN C13

/* Audio config */
#define AUDIO_PIN B1
#define AUDIO_PWM_DRIVER PWMD3
#define AUDIO_PWM_CHANNEL 4
#define AUDIO_PWM_PAL_MODE 42

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
