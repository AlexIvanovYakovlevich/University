CREATE DATABASE Golu
on primary 
(name=sqlcode, 
filename='C:\Golub\sql_code.mdf',
size=5, 
maxsize=100, 
filegrowth=0) 
log on 
(name=sqlcodelog, 
filename='C:\Golub\sql_log.mdf', 
size=1, 
maxsize=40, 
filegrowth=0) 