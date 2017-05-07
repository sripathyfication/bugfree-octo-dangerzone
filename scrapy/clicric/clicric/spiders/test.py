from scrapy.spider import BaseSpider
from scrapy.selector import HtmlXPathSelector
from clicric.items import ClicricItem 


class MySpider(BaseSpider):
      name = "cric"
      allowed_domains = ["espncricinfo.com"]
      start_urls = ["http://www.espncricinfo.com/india-v-new-zealand-2016-17/content/series/1030193.html"]
      
      def parse(self, response):
          hxs = HtmlXPathSelector(response)
          titles = hxs.select("//span[@class='pl']")
          for titles in titles:
              title = titles.select("a/text()").extract()
              link = titles.select("a/@href").extract()
              print title, link

