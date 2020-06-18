/*!
 * @file Adafruit_PS2_Trackpad.h
 */

#ifndef _ADAFRUIT_PS2_H
#define _ADAFRUIT_PS2_H

#define ADAFRUIT_PS2_RESET 0xFF         //!< Resets PS2 device
#define ADAFRUIT_PS2_RESEND 0xFE        //!< Resends command
#define ADAFRUIT_PS2_SETDEFAULTS 0xF6   //!< Used to set the default settings
#define ADAFRUIT_PS2_DISABLE 0xF5       //!< Disables the PS2 device
#define ADAFRUIT_PS2_ENABLE 0xF4        //!< Enables the PS2 device
#define ADAFRUIT_PS2_SETRATE 0xF3       //!< Sets the report rate
#define ADAFRUIT_PS2_GETDEVICEID 0xF2   //!< Gets the device ID
#define ADAFRUIT_PS2_SETPOLL 0xF0       //!< Polls the PS2 device
#define ADAFRUIT_PS2_SETWRAPMODE 0xEE   //!< Turns on wrap mode
#define ADAFRUIT_PS2_RESETWRAPMODE 0xEC //!< Turns off wrap mode
#define ADAFRUIT_PS2_READDATA 0xEB //!< Reads data received from the PS2 device
#define ADAFRUIT_PS2_SETSTREAMMODE 0xEA //!< Turns on streammode
#define ADAFRUIT_PS2_STATUSREQUEST 0xE9 //!< Asks the PS2 device for its status
#define ADAFRUIT_PS2_ERROR 0xFC         //!< PS2 Error response byte
#define ADAFRUIT_PS2_ACK 0xFA           //!< PS2 acknowledge byte

#define ADAFRUIT_PS2_SETRES 0xE8     //!< Sets resolution, sends one argument
#define ADAFRUIT_PS2_SETSCALE11 0xE6 //!< Sets scaling to 1:1
#define ADAFRUIT_PS2_SETSCALE21 0xE7 //!< Sets scaling to 2:1
#define ADAFRUIT_PS2_GETINFO 0xE9    //!< Status request. Receives 3 arg. bytes

#if ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

/*!
 * @brief Adafruit PS2 class
 */
class Adafruit_PS2 {
public:
  /*!
   * @brief PS2 constructor
   * @param c Clock pin
   * @param d Data pin
   */
  Adafruit_PS2(uint8_t c, uint8_t d);
  /*!
   * @brief PS2 constructor
   * @param c Clock pin
   * @param d Data pin
   */
  void constructor(uint8_t c, uint8_t d);
  Adafruit_PS2();

  /*!
   * @brief Writes specified command to PS2 device
   * @param cmd Command to write
   * @return Returns acknowledge byte from PS2 device
   */
  boolean command(uint8_t cmd);
  /*!
   * @brief Writes byte to PS2 device
   * @param x Byte to write to PS2 device
   */
  void write(uint8_t x);
  /*!
   * @brief Reads data from PS2 device
   * @return Returns data read from PS2 device
   */
  uint8_t read(void);
  /*!
   * @brief Puts PS2 device in idle mode
   */
  void idle();
  /*!
   * @brief Prevents PS2 device from sending data
   */
  void inhibit();

private:
  void high(uint8_t p);
  void low(uint8_t p);

  uint8_t _clk, _data;
};

/*!
 * @brief Adafruit PS2 Mouse class
 */
class Adafruit_PS2_Mouse : public Adafruit_PS2 {
public:
  /*!
   * @brief PS2 mouse constructor
   * @param c Clock pin
   * @param d Data pin
   */
  Adafruit_PS2_Mouse(uint8_t c, uint8_t d);
  Adafruit_PS2_Mouse();

  /*!
   * @brief Begins connection with mouse
   * @return Returns false if connection failed
   */
  boolean begin(void);
  /*!
   * @brief Resets the mouse
   * @return Returns true if the mouse was reset
   */
  boolean reset(void);
  /*!
   * @brief Reads whether or not the device was pressed
   * @return Returns true if the device was pressed
   */
  boolean readData(void);
  /*!
   * @brief Reads the device's ID
   * @return Returns the device's ID
   */
  uint8_t readID(void);

  int16_t x;
  /*!<
   * Absolute x coordinate
   */
  int16_t y;
  /*!<
   * Absolute y coordinate
   */
  int16_t z;
  /*!<
   * Absolute z coordinate
   */
  int16_t status;
  /*!<
   * Status of the mouse
   */
  boolean left;
  /*!<
   * Whether the left mouse button was pressed
   */
  boolean right;
  /*!<
   * Whether the right mouse button was pressed
   */
  boolean middle;
  /*!<
   * Whether the middle mouse button was pressed
   */

private:
};

/*!
 * @brief Adafruit PS2 trackpad class
 */
class Adafruit_PS2_Trackpad : public Adafruit_PS2_Mouse {
public:
  /*!
   * @brief Adafruit PS2 Trackpad constructor
   * @param c Clock pin
   * @param d Data pin
   */
  Adafruit_PS2_Trackpad(uint8_t c, uint8_t d);

  /*!
   * @brief Begins connection with trackpad
   * @return Returns false if connection failed
   */
  boolean begin(void);
  /*!
   * @brief Finds out what the scaling is
   * @return Returns the scaling
   */
  uint32_t E6Report(void);
  /*!
   * @brief Finds out what the scaling is
   * @return Returns the scaling
   */
  uint32_t E7Report(void);
  /*!
   * @brief If the touchpad is in absolute mode
   * @return Returns true if the touchpad is in absolute mode
   */
  boolean absoluteMode(void);
  /*!
   * @brief Enables tap mode
   * @param enable Set to true to enable tap mode
   * @return Returns whether or not tap mode is enabled
   */
  boolean tapMode(boolean enable);
  /*!
   * @brief Gets the status of the trackpad
   * @return Returns the status
   */
  uint32_t getStatus(void);
  /*!
   * @brief Reads data from the touchpad
   * @return Returns true if it was read
   */
  boolean readData(void);

  boolean finger;  //!< If a finger is currently pressing
  boolean gesture; //!< If a gesture occured
private:
};
#endif
