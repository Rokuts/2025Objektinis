# Change directory to the script location
Set-Location -Path "C:\Users\Roko PC\Desktop\Objektinis"

# Compile the program using Clang++
Write-Host " Compiling main.cpp..." -ForegroundColor Cyan
& "C:\Program Files\LLVM\bin\clang++.exe" -std=c++20 -fcolor-diagnostics -fansi-escape-codes -g -o "main.exe" `
    "main.cpp" `
    "studentas.cpp" `
    "apskaiciuotas_studentas.cpp" `
    "pagalbines.cpp" `
    "ivedimas.cpp" `
    "rusiavimas.cpp" `
    "isvedimas.cpp" `
    "meniu.cpp" 

# Check if compilation succeeded
if ($LASTEXITCODE -eq 0) {
    Write-Host " Compilation successful!" -ForegroundColor Green

    # Run the compiled executable
    Write-Host " Running main.exe..." -ForegroundColor Cyan
    & ".\main.exe"

    # Store exit code of main.exe
    $exitCode = $LASTEXITCODE

    # Print exit code of main.exe
    Write-Host " main.exe exited with code: $exitCode" -ForegroundColor Yellow
} else {
    Write-Host " Compilation failed! Exit code: $LASTEXITCODE" -ForegroundColor Red
}
