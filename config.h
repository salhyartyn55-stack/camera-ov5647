/*
  ================================================
  OV5647 Camera Configuration File
  ================================================
  فایل تنظیمات برای دوربین OV5647 با Arduino
  ================================================
*/

#ifndef CONFIG_H
#define CONFIG_H

// ================================================
// 1. تنظیمات پین‌های Arduino
// ================================================
#define PIN_CS 10           // Chip Select (SPI)
#define PIN_FIFO_CS 7       // FIFO Chip Select
#define PIN_PCLK 2          // Pixel Clock
#define PIN_HREF 3          // Horizontal Sync
#define PIN_VSYNC 4         // Vertical Sync

// Data Pins (D0-D7)
#define PIN_D0 5
#define PIN_D1 6
#define PIN_D2 7
#define PIN_D3 8
#define PIN_D4 9
#define PIN_D5 11
#define PIN_D6 12
#define PIN_D7 13

// I2C Pins
#define PIN_SDA A4          // Arduino Uno
#define PIN_SCL A5          // Arduino Uno
// برای Arduino Mega: SDA=20, SCL=21

// ================================================
// 2. تنظیمات Serial Communication
// ================================================
#define SERIAL_BAUD 115200  // سرعت Serial (بود ریت)
#define SERIAL_TIMEOUT 1000 // زمان انتظار Serial (ms)

// ================================================
// 3. تنظیمات دوربین
// ================================================

// فرمت تصویر
#define CAMERA_FORMAT JPEG  // JPEG یا RAW

// رزولوشن‌های قابل‌دسترس:
// OV5647_160x120   (QQVGA)  - خیلی کوچک
// OV5647_320x240   (QVGA)   - کوچک (توصیه شده برای Uno)
// OV5647_640x480   (VGA)    - متوسط
// OV5647_1024x768  (XGA)    - بزرگ
// OV5647_1280x960  (SXGA)   - خیلی بزرگ
// OV5647_1600x1200 (UXGA)   - بسیار بزرگ
// OV5647_2048x1536 (QXGA)   - عظیم
// OV5647_2592x1944 (MAX)    - حداکثر (فقط Mega/Due)

#define CAMERA_RESOLUTION OV5647_320x240  // رزولوشن پیش‌فرض

// تنظیمات روشنایی (-4 to 4)
#define BRIGHTNESS_DEFAULT 0
#define BRIGHTNESS_MIN -4
#define BRIGHTNESS_MAX 4

// تنظیمات کنتراست (-4 to 4)
#define CONTRAST_DEFAULT 0
#define CONTRAST_MIN -4
#define CONTRAST_MAX 4

// تنظیمات اشباع رنگ (-4 to 4)
#define SATURATION_DEFAULT 0
#define SATURATION_MIN -4
#define SATURATION_MAX 4

// ================================================
// 4. تنظیمات ثبت تصاویر
// ================================================

// بازه‌ی ثبت تصویر (میلی‌ثانیه)
#define CAPTURE_INTERVAL 5000  // هر 5 ثانیه

// حداکثر تلاش برای ثبت
#define CAPTURE_RETRY_COUNT 3

// زمان انتظار برای ثبت (میلی‌ثانیه)
#define CAPTURE_TIMEOUT 5000

// ================================================
// 5. تنظیمات FIFO
// ================================================

// حداکثر اندازه FIFO (بایت)
// Arduino Uno:  2 KB (2048 بایت)
// Arduino Mega: 8 KB (8192 بایت)
#define FIFO_MAX_SIZE 393216  // برای Mega

// اندازه بافر
#define BUFFER_SIZE 256

// ================================================
// 6. تنظیمات Debug
// ================================================

// فعال/غیرفعال کردن Debug
#define DEBUG_MODE true

// سطح Debug
// 0: بدون Debug
// 1: خطاهای مهم
// 2: اطلاعات کلی
// 3: اطلاعات دقیق
#define DEBUG_LEVEL 2

// نمایش بیت‌های پردازش
#define DEBUG_PROCESSING false

// نمایش اطلاعات SPI
#define DEBUG_SPI false

// نمایش اطلاعات I2C
#define DEBUG_I2C false

// ================================================
// 7. تنظیمات Sensor (OV5647)
// ================================================

// Chip ID
#define OV5647_CHIPID_HIGH 0x56
#define OV5647_CHIPID_LOW 0x47

// Registers
#define OV5647_REG_PIDH 0x300A
#define OV5647_REG_PIDL 0x300B

// ================================================
// 8. تنظیمات SPI
// ================================================

// سرعت SPI (Hz)
#define SPI_SPEED 8000000  // 8 MHz

// Mode SPI
#define SPI_MODE SPI_MODE0

// ================================================
// 9. تنظیمات I2C
// ================================================

// سرعت I2C (Hz)
#define I2C_SPEED 100000  // 100 kHz

// آدرس I2C دوربین
#define CAMERA_I2C_ADDR 0x78

// ================================================
// 10. تنظیمات Timeout
// ================================================

// Timeout اتصال دوربین (ms)
#define INIT_TIMEOUT 2000

// Timeout ثبت تصویر (ms)
#define CAPTURE_TIMEOUT 5000

// Timeout ارسال Serial (ms)
#define SEND_TIMEOUT 10000

// ================================================
// 11. تنظیمات LED (اختیاری)
// ================================================

// فعال/غیرفعال کردن LED
#define USE_LED false

// پین LED
#define PIN_LED 13

// وضعیت‌های LED
#define LED_OFF LOW
#define LED_ON HIGH

// ================================================
// 12. تنظیمات دکمه (اختیاری)
// ================================================

// فعال/غیرفعال کردن دکمه
#define USE_BUTTON false

// پین دکمه
#define PIN_BUTTON 8

// ================================================
// 13. محدودیت‌های Arduino
// ================================================

// نوع Arduino
#define ARDUINO_TYPE_UNO 1
#define ARDUINO_TYPE_MEGA 2
#define ARDUINO_TYPE_LEONARDO 3

// انتخاب نوع Arduino
#define CURRENT_ARDUINO ARDUINO_TYPE_UNO

// حافظه SRAM (بایت)
#if CURRENT_ARDUINO == ARDUINO_TYPE_UNO
  #define SRAM_SIZE 2048      // 2 KB
  #define MAX_RESOLUTION OV5647_320x240
#elif CURRENT_ARDUINO == ARDUINO_TYPE_MEGA
  #define SRAM_SIZE 8192      // 8 KB
  #define MAX_RESOLUTION OV5647_1280x960
#endif

// ================================================
// 14. تنظیمات پیام‌ها
// ================================================

// فعال/غیرفعال کردن پیام‌های سفارشی
#define ENABLE_MESSAGES true

// فرمت پیام‌ها
#define MSG_START "✓"
#define MSG_ERROR "❌"
#define MSG_SUCCESS "✅"
#define MSG_INFO "ℹ️"
#define MSG_CAMERA "📷"
#define MSG_SETTINGS "⚙️"

// ================================================
// 15. تنظیمات توسعه‌دهندگی
// ================================================

// فعال/غیرفعال کردن حالت توسعه
#define DEVELOPMENT_MODE false

// فعال/غیرفعال کردن تست‌های خودکار
#define ENABLE_SELF_TEST false

// فعال/غیرفعال کردن Test Mode
#define TEST_MODE false

// ================================================
// 16. تنظیمات مختلف
// ================================================

// Delay برای مقدار اولیه (ms)
#define INIT_DELAY 1000

// Delay برای تنظیمات (ms)
#define CONFIG_DELAY 500

// Delay برای FIFO (ms)
#define FIFO_DELAY 100

// تعداد تلاش‌های دوباره
#define RETRY_ATTEMPTS 3

// ================================================
// توابع کمکی برای دسترسی تنظیمات
// ================================================

inline bool isDebugMode() {
  return DEBUG_MODE;
}

inline int getDebugLevel() {
  return DEBUG_LEVEL;
}

inline int getCaptureInterval() {
  return CAPTURE_INTERVAL;
}

inline int getMaxResolution() {
  return MAX_RESOLUTION;
}

// ================================================
// پایان فایل کانفینگ
// ================================================

#endif // CONFIG_H
