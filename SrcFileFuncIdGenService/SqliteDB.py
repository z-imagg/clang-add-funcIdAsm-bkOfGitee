#!/usr/bin/env python
# -*- coding: utf-8 -*-

import datetime
from peewee import *

from py_util.Util import IAmNotMain, make_table_name, __print_db_abs_path


# fnDb = SqliteDatabase('fn.db')


class BaseEntity(Model):
    class Meta:
        database = None
        table_function = make_table_name

class SrcFile(BaseEntity):
    fId = AutoField(primary_key=True)
    sF= CharField()
    class Meta: pass

class Func(BaseEntity):
    fnAbsLctId = IntegerField(primary_key=True)
    fId = IntegerField()#引用SrcFile.fId
    funcQualifiedName = CharField()
    line = IntegerField()
    column = IntegerField()

    class Meta:
        #三个字段(fId,line,column)组合唯一
        constraints = [SQL('UNIQUE (fId, line, column)')]





def initDb():
    """
    https://docs.peewee-orm.com/en/latest/peewee/database.html
    https://sqlite.org/pragma.html
    """
    fnDb = SqliteDatabase('fn.db', pragmas={
    'journal_mode': 'wal',
    'cache_size': -1 * 64000,  # 64MB
    })
    __print_db_abs_path(fnDb)

    SrcFile._meta.database = fnDb
    Func._meta.database = fnDb

    fnDb.connect()
    fnDb.create_tables([SrcFile, Func])


def closeDb():
    fnDb:SqliteDatabase=SrcFile._meta.database
    if not fnDb.is_closed():
        fnDb.close()



IAmNotMain(__name__)