#ifndef ECS_H
#define ECS_H

#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ENTITIES 1000
#define MAX_COMPONENTS 32

typedef uint32_t Entity;

typedef struct {
    void* components[MAX_COMPONENTS];
    size_t componentSizes[MAX_COMPONENTS];
    bool componentMasks[MAX_ENTITIES][MAX_COMPONENTS];
} ECS;

void ECS_Init(ECS* ecs);
Entity ECS_CreateEntity(ECS* ecs);
void ECS_DestroyEntity(ECS* ecs, Entity entity);

void ECS_AddComponent(ECS* ecs, Entity entity, uint32_t componentID, void* component, size_t componentSize);
void* ECS_GetComponent(ECS* ecs, Entity entity, uint32_t componentID);
bool ECS_HasComponent(ECS* ecs, Entity entity, uint32_t componentID);

#endif // ECS_H