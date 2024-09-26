#pragma once
enum cms
{
	evNothing = 0,	//Такой команды нет
	evMessage = 100,	//Такая команда есть
	cmAdd = 1,
	cmDel = 2,
	cmGet = 3,
	cmShow = 4,
	cmMake = 5,
	cmQuit = 101
};

//Структура события
struct TEvent
{
	int type;  //Тип события
	int cmcode;
};