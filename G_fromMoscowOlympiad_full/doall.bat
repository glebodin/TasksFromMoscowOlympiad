rem   *** validation ***
call scripts\run-validator-tests.bat
call scripts\run-checker-tests.bat

rem    *** tests ***
md tests
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 4000 20037 142" "tests\04" 4
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 2000 100000 20" "tests\05" 5
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 2000 100000 28" "tests\06" 6
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 1000 100000 200" "tests\07" 7
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 4000 100000 40" "tests\08" 8
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 1000 10000 42" "tests\09" 9
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 100 1500 22" "tests\10" 10
call scripts\gen-input-via-stdout.bat "files\gen_rand.exe 50 300 10" "tests\11" 11
call scripts\gen-answer.bat tests\01 tests\01.a "tests" ""
call scripts\gen-answer.bat tests\02 tests\02.a "tests" ""
call scripts\gen-answer.bat tests\03 tests\03.a "tests" ""
call scripts\gen-answer.bat tests\04 tests\04.a "tests" ""
call scripts\gen-answer.bat tests\05 tests\05.a "tests" ""
call scripts\gen-answer.bat tests\06 tests\06.a "tests" ""
call scripts\gen-answer.bat tests\07 tests\07.a "tests" ""
call scripts\gen-answer.bat tests\08 tests\08.a "tests" ""
call scripts\gen-answer.bat tests\09 tests\09.a "tests" ""
call scripts\gen-answer.bat tests\10 tests\10.a "tests" ""
call scripts\gen-answer.bat tests\11 tests\11.a "tests" ""

