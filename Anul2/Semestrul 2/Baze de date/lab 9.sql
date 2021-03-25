select last_name, department_id, salary, job_id
from employees
where (commission_pct,salary) in (select e.commission_pct, e.salary
                                  from employees e join departments d on (e.department_id=d.department_id)
                                        join locations l on (d.location_id=l.location_id)
                                  where lower(city) = 'oxford');
                                  
select department_id,job_id Job, 
 (select sum(salary)
  from employees
  where department_id=30 and job_id=e.job_id) Dep30,
   (select sum(salary)
  from employees
  where department_id=50 and job_id=e.job_id) Dep50,
   (select sum(salary)
  from employees
  where department_id=80 and job_id=e.job_id) Dep80,
sum(salary) total
from employees e
group by department_id, job_id
order by department_id, job_id;

select (select count(employee_id) from employees) total,
(select count(employee_id)
 from employees
 where to_char(hire_date,'yyyy')=1997) An1997,
 (select count(employee_id)
 from employees
 where to_char(hire_date,'yyyy')=1998) An1998
from dual;

SELECT COUNT(*) AS "Total",
        SUM(DECODE(TO_CHAR(hire_date, 'yyyy'), 1997, 1, 0)) AS "97",
        SUM(DECODE(TO_CHAR(hire_date, 'yyyy'), 1998, 1, 0)) AS "98",
        SUM(DECODE(TO_CHAR(hire_date, 'yyyy'), 1999, 1, 0)) AS "99",
        SUM(DECODE(TO_CHAR(hire_date, 'yyyy'), 2000, 1, 0)) AS "00"
FROM employees;

select last_name, salary, department_id, medie,nr

from employees join (select avg(salary) medie, 
                       count(*) nr,department_id
                      from employees
                      group by department_id) 
using(department_id);   

SELECT department_name, last_name, salary
FROM employees e
right JOIN departments d ON(e.department_id=d.department_id)
WHERE (e.department_id, salary) IN 
                            (SELECT department_id, MIN(salary) minim 
                            FROM employees 
                            GROUP BY department_id) or employee_id is null;
                            
select l.city
from locations l 
where exists(select 'x'
             from departments 
             where location_id = l.location_id);