cmake_minimum_required(VERSION 3.12)
project(program5)

set(CMAKE_CXX_STANDARD 14)

add_executable(program5 main.cpp Transaction.cpp Transaction.h CreditCard.cpp CreditCard.h Check.cpp Check.h Cash.cpp Cash.h LinkedList.h Peer.cpp Peer.h Network.cpp Network.h)
add_executable(program5_test test.cpp Transaction.cpp Transaction.h CreditCard.cpp CreditCard.h Check.cpp Check.h Cash.cpp Cash.h LinkedList.h Peer.cpp Peer.h)