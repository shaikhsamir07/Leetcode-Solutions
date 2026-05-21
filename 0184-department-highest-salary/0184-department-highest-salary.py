import pandas as pd

def department_highest_salary(employee: pd.DataFrame,
                              department: pd.DataFrame) -> pd.DataFrame:

    # Find max salary in each department
    max_salary = employee.groupby('departmentId')['salary'].transform('max')

    # Employees with highest salary
    highest = employee[employee['salary'] == max_salary]

    # Merge with department table
    result = highest.merge(
        department,
        left_on='departmentId',
        right_on='id'
    )

    # Select required columns
    result = result[['name_y', 'name_x', 'salary']]

    # Rename columns
    result.columns = ['Department', 'Employee', 'Salary']

    return result