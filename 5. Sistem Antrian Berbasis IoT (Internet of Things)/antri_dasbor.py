# https://wokwi.com/projects/352926997117535233 (kodingan perangkat)
# modul untuk tkinter
import tkinter as tk
from tkinter import ttk
from tkinter import *

# modul untuk mqtt, tts, mysql, dan waktu
import random
from paho.mqtt import client as mqtt_client
import json
from gtts import gTTS
from playsound import playsound
import os
import mysql.connector
import datetime

# variabel-variabel
antri = 0
sekarang = 0

# bagian database
db = mysql.connector.connect(
    host="localhost",
    user="",
    password="",
    database="antrian_db"
)

# bagian mqtt
broker = 'tcp.ap.ngrok.io'
port = 14272
topic = "antrian"
client_id = f'python-mqtt-{random.randint(0, 100)}'
# fungsi koneksi ke mqtt


def connect_mqtt() -> mqtt_client:
    def on_connect(client, userdata, flags, rc):
        if rc == 0:
            print("Connected to MQTT Broker!")
            # kode dibawah ini dijalankan pertama kali terhadap database
            x = datetime.datetime.now()
            cursor = db.cursor()
            sql = "INSERT INTO antri VALUES (%s, %s, %s)"
            val = ("0", 0, x.strftime("%c"))
            cursor.execute(sql, val)
            db.commit()
        else:
            print("Failed to connect, return code %d\n", rc)

    client = mqtt_client.Client(client_id)
    # client.username_pw_set(username, password) #auth service
    client.on_connect = on_connect
    client.connect(broker, port, 7200)
    return client

# fungsi subscribe mqtt


def subscribe(client: mqtt_client):
    global antri

    def on_message(client, userdata, msg):
        global antri
        nilai = msg.payload.decode()
        nilai = int(nilai)
        if nilai == 1:
            antri += nilai
            Label(root, text='Jumlah antrian :' + str(antri), bg='#FFFFFF',
                  font=('helvetica', 20, 'normal')).place(x=22, y=34)
            #   kode dibawah untuk menambah jumlah antrian ke database
            x = datetime.datetime.now()
            cursor = db.cursor()
            sql = "UPDATE jumlah SET jumlah = " + str(antri) + ", waktu = " + "'" + x.strftime("%c") + "'" + "WHERE num = 1"
            cursor.execute(sql)
            db.commit()
    client.subscribe(topic)
    client.on_message = on_message


# bagian window dashboard dan display nomer antrian
# fungsi2 di window
def btnNext():
    global sekarang, antri
    print('clicked')
    if sekarang < antri:
        sekarang += 1
        Label(root, text='Sekarang :' + str(sekarang), bg='#FFFFFF', font=(
            'helvetica', 20, 'normal')).place(x=23, y=74)
        Label(root2, text=str(sekarang), bg='#FFFFFF',
              font=('helvetica', 370, 'normal')).place(x=70, y=200)
        myobj = gTTS(text='nomor antrian'+str(sekarang), lang='id', slow=False)
        myobj.save("info.mp3")
        playsound("info.mp3")
        x = datetime.datetime.now()
        cursor = db.cursor()
        sql = "INSERT INTO antri (id, nomor_antri, waktu) VALUES (%s, %s, %s)"
        val = ("0", str(sekarang), x.strftime("%c"))
        cursor.execute(sql, val)
        db.commit()


def btnPrev():
    print('clicked')


root = Tk()
root2 = Tk()
# main window
root.geometry('715x314')
root.configure(background='#FFFFFF')
root.title('Dasbor Antrian')
root.resizable(False, False)
# window display antrian
root2.geometry('1366x768')
root2.configure(background='#FFFFFF')
root2.title('Display Antrian')
root2.resizable(False, False)
# label
# label display antrian
Label(root2, text='Antrian :', bg='#FFFFFF',
      font=('helvetica', 60, 'normal')).place(x=22, y=34)
# button
Button(root, text='+', bg='#838B8B', font=('helvetica',
       30, 'normal'), command=btnNext).place(x=477, y=51)
# Button(root, text='-', bg='#838B8B', font=('helvetica',
#        30, 'normal'), command=btnPrev).place(x=482, y=153)
# fungsi running
client = connect_mqtt()
subscribe(client)
client.loop_start()
root.mainloop()
client.loop_stop()
