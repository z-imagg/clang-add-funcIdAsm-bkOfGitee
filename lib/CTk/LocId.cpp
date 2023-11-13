
#include "CTk/LocId.h"

#include "clang/AST/AST.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include <fmt/core.h>
#include "CTk/Util.h"
#include "CTk/SrcFileIdAdmin.h"

using namespace clang;

    const std::string LocId::csv_field_ls="filePath,line,column,locationId,funcName";
    LocId LocId::buildFor(std::string fp, const SourceLocation funcDeclBeginLoc, const clang::SourceManager& SM){

    int srcFileId=SrcFileIdAdmin::getSrcFileId(fp);
      int line;
      int column;
      Util::extractLineAndColumn(SM,funcDeclBeginLoc,line,column);
      return LocId(fp,srcFileId,line,column);
    }

    std::string LocId::to_string(){
      return fmt::format("{},{},{},{},{}",filePath,line,column,locationId,funcName);
    }
LocId:: LocId(
            std::string filePath,int srcFileId,int line, int column)
    :
      filePath(filePath),
      srcFileId(srcFileId),
      line(line),
    column(column),
    locationId(-1)
    {

    }


    // 重写哈希函数
    size_t LocId::operator()(const LocId& that) const {
      // 同一个文件的 在同一个链条（hash）
      return std::hash<std::string>()(that.filePath) ;
    }

    // 重写相等操作符
    bool LocId::operator==(const LocId& that) const {
      return
//      this->stmtClass== that.stmtClass &&
      this->line== that.line
       && this->column== that.column
       && this->filePath== that.filePath
      ;
    }


