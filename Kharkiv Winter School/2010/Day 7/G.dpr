program prefiks;

{$APPTYPE CONSOLE}

uses
  SysUtils;
CONST MY:SET OF CHAR=['+','-','*','/'];
var s:string;
PROCEDURE F_di(VAR S:STRING); forward
PROCEDURE F_mi(VAR S:STRING); forward
PROCEDURE F_mh(VAR S:STRING); forward
PROCEDURE F_pl(VAR S:STRING);
{+}
BEGIN
IF S[1] IN MY THEN
CASE S[1] OF
'+':BEGIN DELETE(S,1,1); F_PL(S); END;
'-':BEGIN DELETE(S,1,1); F_MI(S); END;
'*':BEGIN DELETE(S,1,1); F_MH(S); END;
'/':BEGIN DELETE(S,1,1); F_DI(S); END;
END
ELSE begin WRITE(S[1]); delete(s,1,1); end;
WRITE('+');
IF S[1] IN MY THEN CASE s[1] of
'+':BEGIN DELETE(S,1,1); F_PL(S); END;
'-':BEGIN DELETE(S,1,1); F_MI(S); END;
'*':BEGIN DELETE(S,1,1); F_MH(S); END;
'/':BEGIN DELETE(S,1,1); F_DI(S); END; END ELSE begin  WRITE(S[1]); delete(s,1,1) end;
END;
PROCEDURE F_MI(VAR S:STRING);
{-}
BEGIN
 IF S[1] IN MY THEN
CASE S[1] OF
'+':BEGIN DELETE(S,1,1); F_PL(S); END;
'-':BEGIN DELETE(S,1,1); F_MI(S); END;
'*':BEGIN DELETE(S,1,1); F_MH(S); END;
'/':BEGIN DELETE(S,1,1); F_DI(S); END;
END
ELSE begin WRITE(S[1]); delete(s,1,1) end;
WRITE('-');
IF S[1] IN MY THEN
BEGIN
CASE s[1] of
'+':BEGIN write('('); DELETE(S,1,1); F_PL(S); write(')'); END;
'-':BEGIN write('('); DELETE(S,1,1); F_MI(S); write(')'); END;
'*':BEGIN DELETE(S,1,1); F_MH(S); END;
'/':BEGIN DELETE(S,1,1); F_DI(S); END;
END;
END ELSE begin WRITE(S[1]); delete(s,1,1) end;
END;
PROCEDURE F_MH(VAR S:STRING);
{*}
BEGIN
 IF S[1] IN MY THEN
 BEGIN
CASE S[1] OF
'+':BEGIN  WRITE('('); DELETE(S,1,1); F_PL(S); WRITE(')'); END;
'-':BEGIN  WRITE('('); DELETE(S,1,1); F_MI(S); WRITE(')'); END;
'*':BEGIN DELETE(S,1,1); F_MH(S); END;
'/':BEGIN DELETE(S,1,1); F_DI(S); END;
END;
END
ELSE begin WRITE(S[1]); delete(s,1,1); end;
WRITE('*');
IF S[1] IN MY THEN
BEGIN
CASE s[1] of
'+':BEGIN  WRITE('('); DELETE(S,1,1); F_PL(S);WRITE(')'); END;
'-':BEGIN  WRITE('('); DELETE(S,1,1); F_MI(S); WRITE(')'); END;
'*':BEGIN DELETE(S,1,1); F_MH(S); END;
'/':BEGIN DELETE(S,1,1); F_DI(S); END;
END;
END ELSE begin  WRITE(S[1]); delete(s,1,1) end;
END;
PROCEDURE F_DI(VAR S:STRING);
{/}
BEGIN
 IF S[1] IN MY THEN
 BEGIN
CASE S[1] OF
'+':BEGIN  WRITE('('); DELETE(S,1,1); F_PL(S); WRITE(')'); END;
'-':BEGIN  WRITE('('); DELETE(S,1,1); F_MI(S); WRITE(')'); END;
'*':BEGIN DELETE(S,1,1); F_MH(S); END;
'/':BEGIN DELETE(S,1,1); F_DI(S); END;
END;
END
ELSE begin WRITE(S[1]);delete(s,1,1) end;
WRITE('/');
IF S[1] IN MY THEN
BEGIN
write('(');
CASE s[1] of
'+':BEGIN DELETE(S,1,1); F_PL(S); END;
'-':BEGIN DELETE(S,1,1); F_MI(S); END;
'*':BEGIN DELETE(S,1,1); F_MH(S); END;
'/':BEGIN DELETE(S,1,1); F_DI(S); END;
END;
write(')')
END ELSE begin WRITE(S[1]); delete(s,1,1) end;
END;
begin
 readln(s);
 case s[1] of
 '+':BEGIN DELETE(S,1,1); F_PL(S); END;
'-':BEGIN  DELETE(S,1,1); F_MI(S); END;
'*':BEGIN DELETE(S,1,1); F_MH(S); END;
'/':BEGIN DELETE(S,1,1); F_DI(S); END;
end;
writeln;
end. 
