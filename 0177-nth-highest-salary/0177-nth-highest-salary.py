import pandas as pd

def nth_highest_salary(employee: pd.DataFrame, N: int) -> pd.DataFrame:

    column_name = f'getNthHighestSalary({N})'

    # Handle invalid N
    if N <= 0:
        return pd.DataFrame({column_name: [None]})

    # Get distinct salaries in descending order
    salaries = (
        employee['salary']
        .drop_duplicates()
        .sort_values(ascending=False)
        .reset_index(drop=True)
    )

    # Check if Nth salary exists
    if N > len(salaries):
        return pd.DataFrame({column_name: [None]})

    return pd.DataFrame({
        column_name: [salaries.iloc[N - 1]]
    })