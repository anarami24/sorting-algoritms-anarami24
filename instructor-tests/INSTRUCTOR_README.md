# Instructor Setup Guide for GitHub Classroom Autograding

## Overview
This testing setup provides automated grading for the sorting algorithms assignment with minimal GitHub Actions usage to stay within budget constraints. The tests are kept in a separate private repository to prevent student access.

## Test Design Philosophy
- **Minimal but Comprehensive**: Only 3 tests per algorithm (18 total) to minimize execution time
- **Essential Coverage**: Tests cover basic functionality, duplicates handling, and edge cases
- **Fast Execution**: Entire test suite runs in under 10 seconds
- **Crash Protection**: Tests are wrapped in try-catch to handle segmentation faults gracefully

## Setup Instructions

### Step 1: Create Private Test Repository
1. Create a new **private** repository (e.g., `sorting-algorithms-tests`)
2. Upload the test files:
   ```
   minimal_tests.cpp
   run_tests.sh
   ```
3. Make `run_tests.sh` executable:
   ```bash
   chmod +x run_tests.sh
   ```

### Step 2: Configure GitHub Classroom

1. **Create Repository Secrets** in the GitHub Classroom organization:
   - `TEST_REPO`: Full repository path (e.g., `your-username/sorting-algorithms-tests`)
   - `TEST_REPO_TOKEN`: Personal Access Token with repo access
   
   To create a Personal Access Token:
   - Go to GitHub Settings → Developer settings → Personal access tokens
   - Generate new token (classic)
   - Select scope: `repo` (full control of private repositories)
   - Copy the token and save it as `TEST_REPO_TOKEN` secret

2. **Add Workflow File** to the assignment template:
   - The `.github/workflows/classroom.yml` file should already be in the template
   - This will be automatically copied to each student repository

### Step 3: GitHub Classroom Assignment Settings

1. **Enable Autograding**:
   - In GitHub Classroom, edit your assignment
   - Go to "Add autograding tests"
   - Add a single test called "Run All Tests"
   - Set test command: `echo "Tests run via GitHub Actions"`
   - Points: 100

2. **Enable GitHub Actions**:
   - Ensure GitHub Actions is enabled for the organization
   - Set appropriate usage limits if needed

## Test Scoring

### Grading Breakdown
Each algorithm is worth approximately 16.67 points (100/6):
- Bubble Sort: 16.67 points
- Selection Sort: 16.67 points  
- Insertion Sort: 16.67 points
- Merge Sort: 16.67 points
- Quick Sort: 16.67 points
- Heap Sort: 16.67 points

### Pass/Fail Criteria
- **Pass (exit code 0)**: Overall score ≥ 70%
- **Fail (exit code 1)**: Overall score < 70%

### Test Cases Per Algorithm
1. **Basic Functionality**: Small random array [5,2,8,1,9,3]
2. **Duplicates Handling**: Array with duplicates [3,1,3,2,1,2,3]
3. **Edge Case**: Single element array [42]

## Monitoring and Troubleshooting

### View Test Results
- Check Actions tab in student repositories
- Download test artifacts (test_results.txt)
- Review workflow run logs

### Common Issues

1. **Compilation Errors**:
   - Student's code doesn't compile
   - Score: 0/100
   - Check compilation logs in Actions

2. **Timeouts**:
   - Infinite loops in student code
   - 10-second timeout per test run
   - Score: 0/100

3. **Segmentation Faults**:
   - Caught by try-catch blocks
   - Algorithm scores 0/3 but other tests continue
   - Partial credit possible

### Budget Optimization Tips

1. **Limit Workflow Triggers**:
   - Only run on push to main/master
   - Consider adding path filters:
   ```yaml
   paths:
     - 'src/**.cpp'
     - 'src/**.h'
   ```

2. **Set Organization Limits**:
   - Configure monthly minute limits
   - Set concurrent job limits
   - Monitor usage in Organization Settings → Actions

3. **Reduce Test Frequency**:
   - Consider running only on final submission
   - Use manual workflow triggers for intermediate testing

## Local Testing (For Instructors)

Test the setup locally before deployment:

```bash
# Clone student repository
git clone <student-repo>

# Clone test repository
git clone <test-repo>

# Run tests
cd test-repo
./run_tests.sh ../student-repo

# Check results
cat test_results.txt
```

## Updating Tests

To modify tests:
1. Edit `minimal_tests.cpp` in your private test repository
2. Commit and push changes
3. Tests will automatically use the updated version

## Security Considerations

- **Never** add test files to student repositories
- **Never** make the test repository public
- Rotate Personal Access Tokens periodically
- Review student code for malicious attempts to access test repository

## Support

For issues with the autograding setup:
1. Check GitHub Actions logs
2. Verify secrets are correctly configured
3. Ensure test repository is accessible with the provided token
4. Contact GitHub Classroom support if needed

## Cost Estimation

With minimal test suite:
- Estimated runtime: ~30 seconds per submission (including setup)
- GitHub Actions free tier: 2000 minutes/month
- Supports approximately 4000 submissions per month
- For 100 students with 10 submissions each = 500 minutes (well within limits)