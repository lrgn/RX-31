#include "levels.h"

#include "Level.hpp"
Level* createLevel(uint8_t levelId)
{
	switch (levelId) {case LVL_LEVEL1: return new Level(level1Data, level1entitiesData); default: return NULL;}
}