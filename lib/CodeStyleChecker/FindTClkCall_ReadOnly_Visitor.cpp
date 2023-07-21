#include "CodeStyleChecker/FindTClkCall_ReadOnly_Visitor.h"
#include "CodeStyleChecker/CodeStyleCheckerVisitor.h"
#include "clang/AST/AST.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/FrontendPluginRegistry.h"

using namespace clang;

#include <iostream>
#include <clang/AST/ParentMapContext.h>



bool FindTClkCall_ReadOnly_Visitor::VisitCallExpr(clang::CallExpr *callExpr){
//  std::string fn=callExpr->getDirectCallee()->getNameInfo().getName().getAsString();
  FunctionDecl* dirtCallee=callExpr->getDirectCallee();
  if(dirtCallee){
    //取函数名字
    std::string fn = dirtCallee->getNameInfo().getName().getAsString();
    //记录 该函数 是否 时钟调用语句
    bool is_TCTickCall=fn==CodeStyleCheckerVisitor::funcName_TCTick;
    this->curMainFileHas_TCTickCall=is_TCTickCall;

    //{开发打日志
    if(is_TCTickCall){

//      clang::SourceLocation beginLoc=callExpr->getBeginLoc();
//      clang::SourceRange sourceRange=callExpr->getSourceRange();
//      FileID fileId = SM.getFileID(beginLoc);
//
//      clang::FileID mainFileId = SM.getMainFileID();
//
//      std::string stmtFileAndRange=sourceRange.printToString(SM);
      std::cout<< "" << std::endl;
    }
    //}
  }

  return true;
}





