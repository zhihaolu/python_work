import os

def play_mp3(file_name):
    os.system("ffplay %s"(file_name))