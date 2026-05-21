import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:

    column_name = f'getNthHighestSalary({N})'

    # Invalid N
    if N <= 0:
        return pd.DataFrame({
            column_name: [None]
        })

    unique_salaries = (
        employee['salary']
        .drop_duplicates()
        .sort_values(ascending=False)
        .reset_index(drop=True)
    )

    if N <= len(unique_salaries):
        value = unique_salaries.iloc[N - 1]
    else:
        value = None

    return pd.DataFrame({
        column_name: [value]
    })