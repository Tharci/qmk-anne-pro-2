# Anne Pro 2 Keyboard Firmware

This is a fork of the community-maintained open source Anne Pro 2 keyboard QMK firmware. The firmware for the backlight-handling ECU can be found in the [shine-anne-pro-2](https://github.com/Tharci/shine-anne-pro-2) project. The keyboard's custom Windows driver can be found in the [LitBoard](https://github.com/Tharci/lit-board) project.

![image](https://github.com/user-attachments/assets/5ed17495-d151-4729-9159-cbfcd5e0e946)

## Custom Features

### Keyboard features
- Bunch of layers and macros that significantly improve a programmer's quality of life.
- Lock the keyboard using a combination. The keyboard can only be unlocked by inputting the correct combination. The lock state is saved to persistent memory.
- Complete refactor of the serial communication between the main and the backlight MCUs.

### Backlight features
- Complete refactor and reimplementation of the backlight handling.
- Improved PWM handling of the RGB backlighting for a reduced bleeding effect.
- Overlay effects to easily define and execute extra animations on top of the profile that's set. For example startup effect, blinking effect, indicators, etc.
- The keyboards receives live data to display on backlight profiles
    - Live local weather data: The driver is continuously sending weather updates to the keyboard, so that it can display the outside weather as RGB effects. The keyboard can show sunny, cloudy, partially cloudy, snowy, rainy, stormy weather effects, as well as the temperature and current time on command (by lighting up the numbers in order). The rgb effects also take rain, storm, and snow intensity into account.
    - Audio output for audio visualization: When the keyboard switches to the Audio Visualizer effect, the driver starts sending audio strength played on the default output, split into frequency ranges, so that the keyboard can then visualize the audio.







