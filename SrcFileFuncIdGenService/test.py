#!/usr/bin/env python


from Srv import SFFnIdResp, SFFnIdReq, genFuncAbsLocId, FnDclBgPrsmLoc

fnDclBgPrsmLoc:FnDclBgPrsmLoc=FnDclBgPrsmLoc(line=12,column=4)
reqDto: SFFnIdReq=SFFnIdReq(srcFilePath="/tmp/xxx.c",fnDclBgPrsmLoc=fnDclBgPrsmLoc)
respDto=genFuncAbsLocId(reqDto)
