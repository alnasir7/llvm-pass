#include <string>
#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/Instruction.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Analysis/LoopInfo.h"
#include "llvm/Transforms/Scalar.h"
#include "llvm/Transforms/Utils.h"
#include "llvm/Analysis/LoopPass.h"
#include "llvm/IR/Dominators.h"
#include "llvm/Transforms/Utils/LoopUtils.h"

using namespace llvm;

namespace
{
  struct SkeletonPass : public LoopPass
  {
    static char ID;
    SkeletonPass() : LoopPass(ID) {}

    void getAnalysisUsage(AnalysisUsage &AU) const override
    {
      getLoopAnalysisUsage(AU);
      errs() << "Getting Analysis Usage";
      errs() << "================================";
      AU.addRequired<LoopInfoWrapperPass>();
      AU.setPreservesAll();
    }

    bool runOnLoop(Loop *L, LPPassManager &LPM) override
    {
      //errs() << "Useless loop pass";
      return false;
    }
  };
} // namespace

char SkeletonPass::ID = 0;

// Automatically enable the pass.
// http://adriansampson.net/blog/clangpass.html
static void registerSkeletonPass(const PassManagerBuilder &,
                                 legacy::PassManagerBase &PM)
{
  PM.add(new SkeletonPass());
}

static RegisterPass<SkeletonPass> X("mohamed", "Mohamed Pass",
                                    false /* Only looks at CFG */,
                                    false /* Analysis Pass */);

static RegisterStandardPasses
    RegisterMyPass(PassManagerBuilder::EP_EarlyAsPossible,
                   registerSkeletonPass);
