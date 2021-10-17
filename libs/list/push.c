/*
** EPITECH PROJECT, 2021
** teams
** File description:
** push
*/

#include <stdbool.h>
#include "include/list.h"

static list *push_next(list *_this, char *_value)
{
    list *last = _this->__metadata._last;
    list *new = NULL;

    last->__metadata._next = malloc(sizeof(list));
    new = last->__metadata._next;
    new->__metadata._prev = last;
    new->__metadata._next = NULL;
    new->_value = strdup(_value);
    _this->__metadata._last = new;
    return new;
}

static list *push_current(list *_this, char *_value)
{
    _this->_value = strdup(_value);
    _this->__metadata._fnone = true;
    return _this;
}

list *push_back(list *_this, char *_value)
{
    return (_this->__metadata._fnone) ?
    push_next(_this, _value) : push_current(_this, _value);
}