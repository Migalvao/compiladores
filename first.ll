; ModuleID = 'casos_teste/meta4/first.c'
source_filename = "casos_teste/meta4/first.c"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i8, align 1
  %3 = alloca double, align 8
  store i32 0, i32* %1, align 4
  store i8 10, i8* %2, align 1
  store double 1.000000e+01, double* %3, align 8
  store double 1.000000e+00, double* %3, align 8
  store double 1.700000e+00, double* %3, align 8
  store double 1.000000e+00, double* %3, align 8
  store i8 -1, i8* %2, align 1
  store double 0x4000CCCCCCCCCCCC, double* %3, align 8
  br label %4

4:                                                ; preds = %8, %0
  %5 = load i8, i8* %2, align 1
  %6 = sext i8 %5 to i32
  %7 = icmp sle i32 %6, 90
  br i1 %7, label %8, label %16

8:                                                ; preds = %4
  %9 = load i8, i8* %2, align 1
  %10 = sext i8 %9 to i32
  %11 = call i32 (i32, ...) bitcast (i32 (...)* @putchar to i32 (i32, ...)*)(i32 %10)
  %12 = load i8, i8* %2, align 1
  %13 = sext i8 %12 to i32
  %14 = add nsw i32 %13, 1
  %15 = trunc i32 %14 to i8
  store i8 %15, i8* %2, align 1
  br label %4

16:                                               ; preds = %4
  ret i32 0
}

declare dso_local i32 @putchar(...) #1

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "frame-pointer"="all" "less-precise-fpmad"="false" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 10.0.0-4ubuntu1 "}
