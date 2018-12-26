cmake_minimum_required(VERSION 3.12)
project(interpreterFlight)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS -pthread)

add_executable(interpreterFlight main.cpp FlightReader.cpp FlightReader.h Command.cpp Command.h Expression.cpp Expression.h Number.cpp Number.h BinaryExpression.cpp BinaryExpression.h Plus.cpp Plus.h Minus.cpp Minus.h Div.cpp Div.h Mul.cpp Mul.h InfixToPrefix.cpp InfixToPrefix.h InfixToPrefix.cpp InfixToPrefix.h OpenServerCommand.cpp OpenServerCommand.h ExpressionCommand.cpp ExpressionCommand.h ConnectCommand.cpp ConnectCommand.h DefineVarCommand.cpp DefineVarCommand.h ConditionParser.cpp ConditionParser.h IfCommand.cpp IfCommand.h LoopCommand.cpp LoopCommand.h Sockets.cpp Sockets.h Maps.h Maps.cpp Maps.h EqualCommand.cpp EqualCommand.h BooleanExpression.cpp BooleanExpression.h PrintCommand.cpp PrintCommand.h SleepCommand.cpp SleepCommand.h BindCommand.cpp BindCommand.h EntercCommand.cpp EntercCommand.h)