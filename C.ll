; ModuleID = 'casos_teste/nossos_meta4/C.c'
source_filename = "casos_teste/nossos_meta4/C.c"
target datalayout = "e-m:e-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-pc-linux-gnu"

@global = dso_local global i32 13, align 4

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @func(i32, i32) #0 {
  %3 = alloca i32, align 4
  %4 = alloca i32, align 4
  %5 = alloca i32, align 4
  store i32 %0, i32* %3, align 4
  store i32 %1, i32* %4, align 4
  %6 = load i32, i32* %3, align 4
  %7 = mul nsw i32 2, %6
  %8 = load i32, i32* %4, align 4
  %9 = sdiv i32 8, %8
  %10 = add nsw i32 %7, %9
  store i32 %10, i32* %5, align 4
  %11 = load i32, i32* %5, align 4
  ret i32 %11
}

; Function Attrs: noinline nounwind optnone uwtable
define dso_local i32 @main() #0 {
  %1 = alloca i32, align 4
  %2 = alloca i32, align 4
  %3 = alloca i32, align 4
  %4 = alloca double, align 8
  store i32 0, i32* %1, align 4
  store i32 0, i32* %3, align 4
  store i32 53, i32* %2, align 4
  %5 = load i32, i32* %2, align 4
  %6 = call i32 (i32, ...) bitcast (i32 (...)* @putchar to i32 (i32, ...)*)(i32 %5)
  store double 1.010000e+01, double* %4, align 8
  store i32 43, i32* %2, align 4
  %7 = load i32, i32* %2, align 4
  %8 = call i32 (i32, ...) bitcast (i32 (...)* @putchar to i32 (i32, ...)*)(i32 %7)
  store double 0xBFB9999999999980, double* %4, align 8
  store i32 1, i32* %2, align 4
  store double 0x3FEF5F5F5F5F5F60, double* %4, align 8
  store i32 96, i32* %2, align 4
  %9 = load i32, i32* %2, align 4
  %10 = call i32 (i32, ...) bitcast (i32 (...)* @putchar to i32 (i32, ...)*)(i32 %9)
  store double 2.550000e+01, double* %4, align 8
  store i32 0, i32* %2, align 4
  store i32 1, i32* %2, align 4
  store double 1.000000e+00, double* %4, align 8
  store i32 1, i32* %2, align 4
  store double 1.000000e+00, double* %4, align 8
  store i32 1, i32* %2, align 4
  store i32 0, i32* %2, align 4
  store double 0.000000e+00, double* %4, align 8
  store i32 0, i32* %2, align 4
  store double 0.000000e+00, double* %4, align 8
  store i32 1, i32* %2, align 4
  %11 = load i32, i32* %2, align 4
  %12 = load i32, i32* %3, align 4
  %13 = and i32 %11, %12
  store i32 %13, i32* %2, align 4
  %14 = load i32, i32* %2, align 4
  %15 = icmp ne i32 %14, 0
  br i1 %15, label %16, label %19

16:                                               ; preds = %0
  %17 = load i32, i32* %3, align 4
  %18 = icmp ne i32 %17, 0
  br label %19

19:                                               ; preds = %16, %0
  %20 = phi i1 [ false, %0 ], [ %18, %16 ]
  %21 = zext i1 %20 to i32
  store i32 %21, i32* %2, align 4
  %22 = load i32, i32* %2, align 4
  %23 = load i32, i32* %3, align 4
  %24 = or i32 %22, %23
  store i32 %24, i32* %2, align 4
  %25 = load i32, i32* %2, align 4
  %26 = icmp ne i32 %25, 0
  br i1 %26, label %30, label %27

27:                                               ; preds = %19
  %28 = load i32, i32* %3, align 4
  %29 = icmp ne i32 %28, 0
  br label %30

30:                                               ; preds = %27, %19
  %31 = phi i1 [ true, %19 ], [ %29, %27 ]
  %32 = zext i1 %31 to i32
  store i32 %32, i32* %2, align 4
  %33 = load i32, i32* %2, align 4
  %34 = load i32, i32* %3, align 4
  %35 = xor i32 %33, %34
  store i32 %35, i32* %2, align 4
  %36 = load i32, i32* %2, align 4
  %37 = icmp ne i32 %36, 0
  br i1 %37, label %38, label %41

38:                                               ; preds = %30
  %39 = load i32, i32* %3, align 4
  %40 = icmp ne i32 %39, 0
  br i1 %40, label %50, label %41

41:                                               ; preds = %38, %30
  %42 = load i32, i32* %2, align 4
  %43 = load i32, i32* %3, align 4
  %44 = load i32, i32* %2, align 4
  %45 = and i32 %43, %44
  %46 = load i32, i32* %3, align 4
  %47 = xor i32 %45, %46
  %48 = or i32 %42, %47
  %49 = icmp ne i32 %48, 0
  br label %50

50:                                               ; preds = %41, %38
  %51 = phi i1 [ true, %38 ], [ %49, %41 ]
  %52 = zext i1 %51 to i32
  store i32 %52, i32* %2, align 4
  store i32 1, i32* %2, align 4
  %53 = load i32, i32* %2, align 4
  %54 = icmp ne i32 %53, 0
  %55 = xor i1 %54, true
  %56 = zext i1 %55 to i32
  store i32 %56, i32* %2, align 4
  %57 = call i32 @func(i32 20, i32 4)
  store i32 %57, i32* %2, align 4
  %58 = load i32, i32* %2, align 4
  %59 = call i32 (i32, ...) bitcast (i32 (...)* @putchar to i32 (i32, ...)*)(i32 %58)
  %60 = call i32 (...) @getchar()
  store i32 %60, i32* %2, align 4
  ret i32 0
}

declare dso_local i32 @putchar(...) #1

declare dso_local i32 @getchar(...) #1

attributes #0 = { noinline nounwind optnone uwtable "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "min-legal-vector-width"="0" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-jump-tables"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "correctly-rounded-divide-sqrt-fp-math"="false" "disable-tail-calls"="false" "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "no-signed-zeros-fp-math"="false" "no-trapping-math"="false" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.module.flags = !{!0}
!llvm.ident = !{!1}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{!"clang version 9.0.1-12 "}
