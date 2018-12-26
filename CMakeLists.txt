cmake_minimum_required(VERSION 3.13)
project(untitled5)
set(CMAKE_CXX_FLAGS -pthread)
set(CMAKE_CXX_STANDARD 14)

add_executable(untitled5 Number.cpp Number.h Expression.h Plus.cpp Plus.h Minus.cpp Minus.h LexParse.cpp LexParse.h BinaryExpression.cpp BinaryExpression.h Div.cpp Div.h Mul.cpp Mul.h Shunting.cpp Shunting.h Command.h CommandExpression.cpp CommandExpression.h OpenDataServerCommand.cpp OpenDataServerCommand.h ConnectCommand.cpp ConnectCommand.h SleepCommand.cpp SleepCommand.h WhileCommand.cpp WhileCommand.h PrintCommand.cpp PrintCommand.h IfCommand.cpp IfCommand.h AssignCommand.cpp AssignCommand.h VarCommand.cpp VarCommand.h VarBindCommand.cpp VarBindCommand.h main.cpp ConditionCommand.cpp ConditionCommand.h OpenDataReader.cpp OpenDataReader.h mapsData.cpp mapsData.h ClientWriter.cpp ClientWriter.h)