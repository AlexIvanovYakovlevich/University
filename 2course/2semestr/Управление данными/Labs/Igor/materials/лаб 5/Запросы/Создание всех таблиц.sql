CREATE TABLE ������
("���� ������" Integer primary key Not null,
������������ Varchar (100) Not null,
���� Integer Not null);

CREATE TABLE ��������
("���� ��������" Integer primary key Not null,
"���� ������" Integer Not null,
��� Varchar (100) Not null,
������� Integer Not null,
��� Varchar (40) Not null);

CREATE TABLE �������
("���� ������" Integer Not null,
"���� ��������" Integer Not null,
"���� ������" Integer Not null,
���� Date Not null,
����������� Decimal (4,2) Not null);

CREATE TABLE ������
("���� ������" Integer primary key Not null,
������������ Varchar (100) Not null,
"��� ������� ���������" Varchar (40) Not null,
"��������� ������� ���������" Money Not null);