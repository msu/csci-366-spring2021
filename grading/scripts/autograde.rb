#!/home/carson/.rvm/rubies/ruby-2.6.2/bin/ruby -w

require 'octokit'
require 'csv'

# =====================================================================
#  github setup
# =====================================================================
git_token = ENV["GITHUB_TOKEN"]
unless git_token
  throw "You must set the GITHUB_TOKEN environment variable"
end
client = Octokit::Client.new(:access_token => git_token)
client.auto_paginate = true
user = client.user
git_username = user.login
class_repo_name = "msu/csci-366-fall2020"
class_repo_url = "https://github.com/#{class_repo_name}"
puts("github user id: #{user.login}")

# =====================================================================
#  helper functions
# =====================================================================

def each_student
  results = CSV.read("students.csv", headers: true)
  results.each do |row|
    yield row
  end
end

def for_each_student_dir
  each_student do |student|
    dir = "repos/#{student_dir(student)}"
    if Dir.exist? dir
      Dir.chdir dir do
        yield student["FIRST_NAME"], student["LAST_NAME"], dir
      end
    else
      puts "Directory #{dir} does not exist"
    end
  end
end

def student_dir(student)
  student["FIRST_NAME"].downcase + "_" + student["LAST_NAME"].downcase
end

def maven_test(pattern, output_file)
  puts `mvn -B "-Dtest=#{pattern}" test > #{output_file} 2> err.out`
end

def cmake(output_file)
    puts `cmake . > tmp.out; make > #{output_file} 2> err.out;`
end

def maybe_exec(command, output_file)
    begin
        output = `#{command}`
        File.open(output_file, 'w') do |file|
            file.write output
        end
    rescue
        puts "Could not execute #{command}"
    end
end

def pull
  puts `git pull`
end

def push_grading
  puts `git add grading/*; git commit -m "From Autograder"; git push`
end

def grading_dir_exist?
  Dir.exist? "grading"
end

def make_grading_dir
  Dir.mkdir "grading" unless Dir.exist? "grading"
end

# =====================================================================
#  command line
# =====================================================================

case ARGV[0]
when "accept_invites"
  puts("Accepting Repository Invites")
  puts("------------------")
  client.user_repository_invitations.each do |ri|
    puts "  Accepting #{ri[:id]}: #{ri[:repository][:full_name]}"
    client.accept_repo_invitation(ri[:id])
  end
when "grade"
  assignment = ARGV[1]
  filter = ARGV[2]
  case assignment
  when "hwk2"
    for_each_student_dir do |first, last, dir|
      if filter and not "#{first} #{last}".downcase.include?(filter.downcase)
        next
      end
      puts "Grading #{assignment} for #{first} #{last} in #{dir}"
      pull
      make_grading_dir
      if not Dir.exist? 'homework_2'
        next
      end
      Dir.chdir 'homework_2' do
        cmake "../grading/homework_2_results.txt"
        maybe_exec "./homework_2", "../grading/homework_2_results.txt"
      end
      push_grading
    end
  else
    puts "Unknown assignment: #{assignment} (expected hwk2)"
  end
when "clone_repos"
  each_student do |student|
    student_dir = student_dir(student)
    if Dir.exist? student_dir
      puts "Directory #{student_dir} already exists, skipping..."
    else
      repo_url = student["REPO"].gsub("https://", "")
      if repo_url.nil? || repo_url.strip.empty?
        puts("No git URL for #{student["FIRST_NAME"]} #{student["LAST_NAME"]}")
        next
      end
      `git clone https://#{git_username}:#{git_token}@#{repo_url} repos/#{student_dir}`
    end
  end
when "clear_repos"
  `rm -rf repos/*`
else
  puts "Commands:
    accept_invites - accepts pending invites
    clone_repos - clones student repos to the repos directory
    clear_repos - removes all repos from the current dir
    grade <assignment> [student name] - grades the given assignment and pushes it (homework_4, project)"
end
