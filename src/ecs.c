#include "ecs.h"
#include <string.h>

void ECS_Init(ECS* ecs) {
    memset(ecs, 0, sizeof(ECS));
}

Entity ECS_CreateEntity(ECS* ecs) {
    static Entity nextEntity = 0;
    return nextEntity++;
}

void ECS_DestroyEntity(ECS* ecs, Entity entity) {
    for (uint32_t i = 0; i < MAX_COMPONENTS; ++i) {
        ecs->componentMasks[entity][i] = false;
    }
}

void ECS_AddComponent(ECS* ecs, Entity entity, uint32_t componentID, void* component, size_t componentSize) {
    if (componentID >= MAX_COMPONENTS) return;
    if (ecs->components[componentID] == NULL) {
        ecs->components[componentID] = malloc(MAX_ENTITIES * componentSize);
        ecs->componentSizes[componentID] = componentSize;
    }
    memcpy((uint8_t*)ecs->components[componentID] + entity * componentSize, component, componentSize);
    ecs->componentMasks[entity][componentID] = true;
}

void* ECS_GetComponent(ECS* ecs, Entity entity, uint32_t componentID) {
    if (componentID >= MAX_COMPONENTS || !ecs->componentMasks[entity][componentID]) return NULL;
    return (uint8_t*)ecs->components[componentID] + entity * ecs->componentSizes[componentID];
}

bool ECS_HasComponent(ECS* ecs, Entity entity, uint32_t componentID) {
    if (componentID >= MAX_COMPONENTS) return false;
    return ecs->componentMasks[entity][componentID];
}