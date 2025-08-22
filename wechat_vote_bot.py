import time
import random
import undetected_chromedriver as uc
from selenium.webdriver.common.by import By
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC
from selenium.webdriver import ActionChains


class WeChatVoteBot:
    def __init__(self):
        options = uc.ChromeOptions()
        options.add_argument("--start-maximized")
        options.add_argument("--disable-blink-features=AutomationControlled")
        user_agents = [
            "Mozilla/5.0 (Windows NT 10.0; Win64; x64) Chrome/125.0.0.0 Safari/537.36"
        ]
        options.add_argument(f"--user-agent={random.choice(user_agents)}")
        self.driver = uc.Chrome(options=options)
        self.wait = WebDriverWait(self.driver, 20)
        self.logged_in = False

    def vote(self, vote_url, candidate_name):
        try:
            print("🌐 正在访问投票页面...")
            self.driver.get(vote_url)
            time.sleep(random.uniform(3, 5))

            if not self.logged_in:
                self.handle_login_prompt()
                self.logged_in = True

            self.simulate_browsing()
            if not self.select_candidate(candidate_name):
                return False
            self.click_submit_vote()
            self.handle_captcha()
            self.confirm_vote_success()
            return True
        except Exception as e:
            print(f"❌ 投票失败: {e}")
            return False

    def handle_login_prompt(self):
        try:
            self.wait.until(EC.presence_of_element_located((By.ID, "login_container")))
            input("⚠️ 需要微信扫码登录，完成后按回车继续...")
        except:
            print("✅ 无需登录，继续...")

    def simulate_browsing(self):
        print("🔄 模拟人类浏览行为...")
        for y in [300, 600]:
            self.driver.execute_script(f"window.scrollTo(0, {y});")
            time.sleep(random.uniform(1, 2))
        self.driver.execute_script("window.scrollTo(0, 0);")
        time.sleep(2)

    def select_candidate(self, candidate_name):
        name = candidate_name.strip()
        print(f"🎯 正在选择候选人：{name}")

        # 1. 先检测候选人是否存在
        candidate_xpath = f'//span[@class="vote_option_name" and text()="{name}"]'
        try:
            self.wait.until(EC.presence_of_element_located((By.XPATH, candidate_xpath)))
        except:
            print(f"❌ 未找到候选人：{name}")
            return False

        # 2. 点击选项（假设结构为 label > input + span）
        click_xpath = f'//span[@class="vote_option_name" and text()="{name}"]/parent::div/preceding-sibling::input[1]'
        try:
            option = self.wait.until(EC.element_to_be_clickable((By.XPATH, click_xpath)))
            self.scroll_and_click(option)
            print(f"✅ 已选择：{name}")
            return True
        except:
            # 备用：直接点击 label
            click_xpath2 = f'//label[.//span[@class="vote_option_name" and text()="{name}"]]'
            try:
                option = self.wait.until(EC.element_to_be_clickable((By.XPATH, click_xpath2)))
                self.scroll_and_click(option)
                print(f"✅ 已选择：{name}")
                return True
            except:
                print(f"❌ 无法点击候选人：{name}")
                return False

    def click_submit_vote(self):
        selectors = [
            '//button[contains(text(), "投票") or contains(text(), "提交")]',
            '//div[@class="vote_btn" or @class="vote_submit"]'
        ]
        for sel in selectors:
            try:
                btn = self.wait.until(EC.element_to_be_clickable((By.XPATH, sel)))
                self.scroll_and_click(btn)
                print("✅ 已点击提交投票")
                time.sleep(random.uniform(2, 4))
                return
            except:
                continue
        raise Exception("找不到提交按钮")

    def scroll_and_click(self, element):
        self.driver.execute_script("arguments[0].scrollIntoView({block: 'center'});", element)
        time.sleep(1)
        ActionChains(self.driver).move_to_element(element).pause(0.5).click().perform()

    def handle_captcha(self):
        try:
            captcha = self.wait.until(EC.visibility_of_element_located((By.CLASS_NAME, "captcha-container")))
            input("⚠️ 检测到验证码，请手动处理后按回车继续...")
        except:
            print("✅ 无验证码")

    def confirm_vote_success(self):
        success_msgs = ["投票成功", "感谢您的投票", "已投票", "投票已提交"]
        for msg in success_msgs:
            try:
                self.driver.find_element(By.XPATH, f"//*[contains(text(), '{msg}')]")
                print("✅ 投票成功确认")
                return
            except:
                continue
        print("⚠️ 未检测到明确成功提示，请手动确认")

    def close(self):
        self.driver.quit()
        print("🧹 浏览器已关闭")


def main():
    print("🗳️ 微信公众号投票自动化（精准候选人版）")
    url = input("请输入投票链接: ").strip()
    try:
        times = int(input("请输入投票次数: "))
    except:
        times = 1

    candidate = input("请输入候选人名字（如“爆照09”）: ").strip()

    bot = WeChatVoteBot()
    try:
        for i in range(1, times + 1):
            print(f"\n🔁 第 {i}/{times} 次投票...")
            success = bot.vote(url, candidate)
            if success and i < times:
                sleep_time = random.randint(60, 120)
                print(f"⏳ 等待 {sleep_time} 秒后下一次...")
                time.sleep(sleep_time)
    except KeyboardInterrupt:
        print("⏹️ 用户中断")
    finally:
        bot.close()


if __name__ == "__main__":
    main()
