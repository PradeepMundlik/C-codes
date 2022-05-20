from win32com.client import Dispatch
import json
import requests as re

def speak(str):
    speak = Dispatch("SAPI.SpVoice")
    speak.speak(str)


if __name__ == '__main__' : 
    f = re.get("https://newsapi.org/v2/top-headlines?country=us&pageSize=10&apiKey=af2c3581e4504285a8c942f62b3d65d0")
    b = json.loads(f.text)
    i = 0
    print("TOP 10 NEWS IN US:")
    speak("TOP 10 NEWS IN US:")
    for k in b['articles']:
        i += 1
        print(f"{i}. {k['title']}")
        speak(f"News number {i}. {k['title']}")
    