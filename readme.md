This is a small experiment to understand the difference between 74HC595 and TPIC6C595 in order to implement version two of: https://github.com/MMDavito/8_switch_rgb

# On 74HC595:
byte dataToTransfer = 0b00000001;//== Qa on MSBFIRST, Qh on LSBFIRST

# On TPIC6C595:
