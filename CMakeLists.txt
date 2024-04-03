cmake_minimum_required(VERSION 3.15)
project(DesignPattern)
find_package( OpenCV REQUIRED )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread ")
set(CMAKE_CXX_STANDARD 11)

include_directories(${OpenCV_INCLUDE_DIRS})
add_executable( DesignPattern main.cpp Sigleton.cpp Sigleton.h
                Factory.cpp Factory.h Prototype.cpp Prototype.h
                Builder.cpp Builder.h Adapter.cpp Adapter.h Bridge.cpp Bridge.h
                Decorator.cpp Decorator.h Composite.cpp Composite.h Facade.cpp Facade.h
                Flyweight.cpp Flyweight.h Proxy.cpp Proxy.h DynamicProxy.cpp DynamicProxy.h
                TemplateMethod.cpp TemplateMethod.h ThreadCommand.cpp ThreadCommand.h Visitor.h Iterator.h ChainOfResponsibility.h ChainOfResponsibility.cpp Observer.cpp Observer.h Strategy.cpp Strategy.h Command.cpp Command.h mediator.cpp mediator.h Memento.cpp Memento.h)
target_link_libraries(DesignPattern ${OpenCV_LIBS})