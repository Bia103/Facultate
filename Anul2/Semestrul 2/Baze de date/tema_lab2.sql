/* 1 */
SELECT  first_name||' '|| last_name||' castiga '|| salary||' lunar, dar doreste '|| 3*salary AS "Salariu Ideal"
FROM EMPLOYEES ;

/* 2 */
SELECT INITCAP(first_name) AS "Prenume", UPPER(last_name) AS "NUME", LENGTH(last_name) AS "Lungimea numelui"
FROM EMPLOYEES
WHERE UPPER(first_name) LIKE 'J%' OR UPPER(first_name) LIKE 'M%'  OR UPPER(first_name) LIKE '__A%'
ORDER BY LENGTH(last_name) DESC;

/* 3 */
SELECT employee_id, first_name, last_name, department_id
FROM EMPLOYEES
WHERE UPPER(first_name) = 'STEVEN';

/* 4 */
SELECT employee_id, first_name, last_name, LENGTH(last_name) AS "Lungimea numelui", INSTR(LOWER(last_name),
'a') 
FROM EMPLOYEES
WHERE last_name LIKE '%e';

/* 5 */
SELECT  first_name
FROM EMPLOYEES 
WHERE MOD((SYSDATE - HIRE_DATE), 7) = 0;

/* 6 */
SELECT  employee_id,first_name, salary,cast(FLOOR(salary + FLOOR(FLOOR(salary)*15)/100) as decimal(10,2))
FROM EMPLOYEES ;

/* 8 */
SELECT SYSDATE + 30
FROM EMPLOYEES;

/*9*/
select to_date('31-12-' || to_char(sysdate, 'yyyy'), 'dd-mm-yyyy')-sysdate
from dual;

/* 12 */
SELECT last_name, MONTHS_BETWEEN(to_char(sysdate, 'dd-mm-yyyy'), hire_date) "Luni lucrate"
FROM employees;

/* 14 */
SELECT last_name, nvl(to_char(commission_pct),  'Fara comision') 'Comision'
FROM employees;

/* 15 */
SELECT last_name, salary, commission_pct
FROM employees
WHERE salary * (1 + nvl(commission_pct, 0)) > 10000;

