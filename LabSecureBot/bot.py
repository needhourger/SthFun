# -*- coding:utf-8 -*-
import time
import requests
import os
import json
import signal

url_learn="http://examsafety.nuist.edu.cn/exam_xuexi_online.php"
url_login="http://examsafety.nuist.edu.cn/exam_login.php"
headers_login={
"Host":"examsafety.nuist.edu.cn",
"Cache-Control": "max-age=0",
"Origin": "http://examsafety.nuist.edu.cn",
"Upgrade-Insecure-Requests": "1",
"Content-Type":"application/x-www-form-urlencoded",
"User-Agent": "Mozilla/5.0 (Linux; X11)",
"Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/apng,*/*;q=0.8",
"Referer": "http://examsafety.nuist.edu.cn/index.php",
"Accept-Encoding": "gzip, deflate",
"Accept-Language": "zh-CN,zh;q=0.9",
"Connection":"close"
}

headers_lean={
"Host": "examsafety.nuist.edu.cn",
"Content-Length": "16",
"Accept": "*/*",
"Origin": "http://examsafety.nuist.edu.cn",
"X-Requested-With": "XMLHttpRequest",
"User-Agent": "Mozilla/5.0 (Linux; X11)",
"Content-Type": "application/x-www-form-urlencoded; charset=UTF-8",
"Referer": "http://examsafety.nuist.edu.cn/redir.php?catalog_id=121&object_id=17926",
"Accept-Encoding": "gzip, deflate",
"Accept-Language": "zh-CN,zh;q=0.9",
"Connection":"close"
}

headers_logout={
"Host": "examsafety.nuist.edu.cn",
"Upgrade-Insecure-Requests":"1",
"User-Agent": "Mozilla/5.0 (Linux; X11)",
"Content-Type": "application/x-www-form-urlencoded; charset=UTF-8",
"Referer": "http://examsafety.nuist.edu.cn/",
"Accept-Encoding": "gzip, deflate",
"Accept-Language": "zh-CN,zh;q=0.9",
"Connection":"close"
}

s=requests.Session()

def login(xuehao="",password=""):
    data={"xuehao":xuehao,"password":password,"cmd":"login","postflag":"1"}
    try:
        r=s.post(url_login,data=data,headers=headers_login)
    except:
        print("远程服务器错误，请稍后尝试！")
        time.sleep(1.5)
        exit()
    ret=r.text
    if "if (window.parent != window)" in ret:
        return True
    else:
        return False


def logout():
    data={"cmd":"logout"}
    r=s.get(url_login,data=data)
    print (r.text)

def learn():
    print("您已经学习了：",end="")
    data={"cmd":"xuexi_online"}
    r=s.post(url_learn,data=data,headers=headers_lean)
    temp=r.text
    ret=json.loads(temp)
    print (ret["shichang"])
    
def print_log():
    os.system("cls")
    print("__   _   _   _   _   _____   _____        _       _____        _____   _____   _____  ")
    print("|  \ | | | | | | | | /  ___/ |_   _|      | |     /  ___/      |  _  \ /  _  \ |_   _| ")
    print("|   \| | | | | | | | | |___    | |        | |     | |___       | |_| | | | | |   | |   ")
    print("| |\   | | | | | | | \___  \   | |        | |     \___  \      |  _  { | | | |   | |   ")
    print("| | \  | | |_| | | |  ___| |   | |        | |___   ___| |      | |_| | | |_| |   | |   ")
    print("|_|  \_| \_____/ |_| /_____/   |_|        |_____| /_____/      |_____/ \_____/   |_|   ")
    print("=======================================================================================")
    print("NUIST Lab Secure Bot       also thanks for 啊哈呵嗨's js code   --Code by cc")
    print("")

def get_info():
    print("请输入您的用户信息：")
    xuehao=input("学号：")
    password=input("密码：")
    return xuehao,password

def stol_exit(signum,frame):
    print ("正在退出账号...")
    logout()
    time.sleep(1)
    exit(0)


if __name__=="__main__":
    signal.signal(signal.SIGTERM,stol_exit)
    signal.signal(signal.SIGINT,stol_exit)
    xuehao=""
    password=""
    while (not(login(xuehao,password))):
        print_log()
        xuehao,password=get_info()
    
    print("登陆成功")
    print("开始挂机")
    time.sleep(1.5)

    while (True):
        print_log()
        learn()
        time.sleep(60)
