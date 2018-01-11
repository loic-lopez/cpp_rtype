//
// Created by Loic Dupil on 11/01/2018.
//

#include "GameEngine.h"

GameEngine GameEngine::m_Instance = GameEngine::GameEngine();

template<class T>
GameEngine<T>::GameEngine()
{

}

template<class T>
GameEngine<T>::~GameEngine()
{

}

void GameEngine::run()
{

}

template<class T>
void GameEngine<T>::addThing(T *object)
{

}

template<class T>
void GameEngine<T>::checkHitBoxes()
{

}


template<class T>
GameEngine<T>::Thing::Thing()
{

}

template <class T>
void GameEngine::start()
{
    //thread(&GameEngine::run);
  std::thread([] () {

  });
}