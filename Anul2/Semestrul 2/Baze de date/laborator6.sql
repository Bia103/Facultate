SELECT REPLACE('aaai', 'a')
from dual;

select length(TRANSLATE('andreea', 'aeiou', ' ')) - 1
from dual;

select last_name, initcap(replace(translate(lower(last_name),'aeiou','#'),'#'))
from employees;

/* 11 */

SELECT last_name || '  ' || first_name "NUME", hire_date,
       NEXT_DAY(ADD_MONTHS(hire_date, 6), 'Luni') "Negociere" 
FROM employees;

SELECT last_name, job_id, salary,decode(job_id,'IT_PROG', salary*1.2,'SA_REP', salary*1.25,'SA_MAN', salary*1.35,salary) "Salariu renegociat"
from employees;

SELECT last_name, job_id, salary, salary*(
CASE job_id
when 'IT_PROG' then 1.2
WHEN 'SA_PEP'then 1.25
when 'SA_MAN' then 1.35
else 1
end) "SALARIU Renegociat"
from EMPLOYEES;

SELECT last_name, job_id, salary, salary*(
CASE 
when job_id = 'IT_PROG' then 1.2
WHEN job_id='SA_PEP'then 1.25
when job_id='SA_MAN' then 1.35
else 1
end) "SALARIU Renegociat"
from EMPLOYEES;

select last_name, job_id, salary,
salary*
(case  
  when job_id in ('IT_PROG', 'SH_CLERK') then 1.2
  when job_id='SA_REP' then 1.25
  when job_id='SA_MAN' then 1.35
  else 1
  end) "Salariu renegociat"
from employees;

select unique j.job_title
from employees e join jobs j
on (e.job_id = j.job_id)
where e.department_id = 30;

select ang.last_name, to_char(ang.hire_date,'month-yyyy'),
ang.employee_id,ang.department_id
from employees ang join employees gates 
on(ang.department_id=gates.department_id)
where lower(ang.last_name) like '%a%' and 
lower(gates.last_name)='gates' and 
lower(ang.last_name)!='gates';


select distinct ang.employee_id, ang.last_name, ang.department_id, 
department_name
from employees ang join employees t 
on(ang.department_id=t.department_id)
      join departments d on (ang.department_id = d.department_id)
where lower(t.last_name) like '%t%' and
ang.employee_id<>t.employee_id
order by ang.last_name;


SELECT department_id
FROM departments
minus
SELECT department_id
FROM employees;


select department_id
from departments
where lower(department_name) like '%re%'
intersect
select department_id
from employees
where upper(job_id) ='HR_REP';

select employee_id,job_id,last_name
from employees
where salary > 3000
union
select employee_id,employees.job_id,last_name
from employees join jobs on(employees.job_id = jobs.job_id)
where salary = (min_salary + max_salary)/2