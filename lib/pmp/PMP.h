//
// Created by dylan on 6/27/2023.
//

#ifndef PIBBY_PMP_H
#define PIBBY_PMP_H

#include "fatfs_storage.c"

typedef struct {
    uint32_t width;
    uint32_t height;
    uint8_t *data;
} PMP;

PMP Load_Image(char *);

void Save_Image(char *, uint8_t *, uint32_t, uint32_t);

#endif
