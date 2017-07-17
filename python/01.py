#coding:utf-8
import urllib2
import lxml.html
import re
import  time
import urlparse
from bs4 import BeautifulSoup


def download(url,user_agent='wswp',num_retries=2):
    print("Downloading:",url)
    headers = {"User-agent":user_agent}
    request = urllib2.Request(url,headers=headers)
    try:
        html = urllib2.urlopen(request).read()
    except urllib2.URLError as e:
        print("Download error",e.reason)
        html = None
        if num_retries>0:
            if hasattr(e,'code') and 500<= e.code < 600:
                return download(url,user_agent,num_retries-1)
    return html



def get_links(html):
    webpage_regex = re.compile('<a[^>]+href=["\'](.*?)["\']',re.IGNORECASE)
    return webpage_regex.findall(html)

def link_crawler(seed_url,link_regex=None):
    #保存还没有下载过的url
    crawl_queue = [seed_url];
    #保存已经下载过的url
    seen = set(crawl_queue)
    while crawl_queue:
        url = crawl_queue.pop()
        html = download(url)
        for link in get_links(html):
            #处理路径
            link = urlparse.urljoin(seed_url,link)
            if link not in seen:
                seen.add(link)
                crawl_queue.append(link)



FILEDS=('national_flag','area','population','iso','country',
        'capital','continent','tld','currency_name','phone',
        'postal_code_format','postal_code_regex','languages','neighbours')


def bs_scraper(html):
    soup = BeautifulSoup(html,'html.parser')
    results = {}
    for field in FILEDS:
        results[field] = soup.find('table').find('tr',id='places_%s__row' % field).find('td',class_='w2p_fw').text
    return results

def re_scraper(html):
    results = {}
    for field in FILEDS:
        results[field] = re.search('<tr id="places_%s__row">.*?<td class="w2p_fw">(.*?)</td>' % field,html).groups(0)
    return results


def lxml_scraper(html):
    tree = lxml.html.fromstring(html)
    results = {}
    for field in FILEDS:
        results[field] = tree.cssselect('table>tr#places_%s__row>td.w2p_fw' %field)[0].text_content()
    return results


NUM_ITERATIONS = 1000
html = download('http://example.webscraping.com/places/default/view/Armenia-12')
for name,scraper in [('Regular expressions',re_scraper),('BeautifulSoup',bs_scraper),('Lxml',lxml_scraper)]:
    start = time.time()
    for  i in range(NUM_ITERATIONS):
        if scraper == re_scraper:
            re.purge()
        result = scraper(html)
    end = time.time()
    print("%s:%.2f seconds" %(name,end-start))

